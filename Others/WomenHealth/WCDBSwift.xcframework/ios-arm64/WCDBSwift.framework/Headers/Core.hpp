//
// Created by sanhuazhang on 2019/05/02
//

/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "OperationQueue.hpp"

#include "Config.hpp"
#include "Configs.hpp"
#include "PerformanceTraceConfig.hpp"
#include "SQLTraceConfig.hpp"

#include "DatabasePool.hpp"

#include "AuxiliaryFunctionModules.hpp"
#include "TokenizerModules.hpp"

#include "Notifier.hpp"

namespace WCDB {

// The order of member variables here is important.
class Core final : public DatabasePoolEvent, public OperationEvent {
#pragma mark - Core
public:
    static Core& shared();
    ~Core() override final;

protected:
    Core();
    Core(const Core&) = delete;
    Core& operator=(const Core&) = delete;

#pragma mark - Database
public:
    RecyclableDatabase getOrCreateDatabase(const UnsafeStringView& path);

    void purgeDatabasePool();
    void setThreadedDatabase(const UnsafeStringView& path);

protected:
    void preprocessError(Error& error);
    void databaseDidCreate(InnerDatabase* database) override final;
    DatabasePool m_databasePool;
    ThreadLocal<StringView> m_associateDatabases;

#pragma mark - Tokenizer
public:
    void registerTokenizer(const UnsafeStringView& name, const TokenizerModule& module);
    std::shared_ptr<Config> tokenizerConfig(const UnsafeStringView& tokenizeName);
    bool tokenizerExists(const UnsafeStringView& name) const;

protected:
    std::shared_ptr<TokenizerModules> m_tokenizerModules;

#pragma mark - AuxiliaryFunction
public:
    void registerAuxiliaryFunction(const UnsafeStringView& name,
                                   const FTS5AuxiliaryFunctionModule& module);
    std::shared_ptr<Config>
    auxiliaryFunctionConfig(const UnsafeStringView& auxiliaryFunctionName);
    bool auxiliaryFunctionExists(const UnsafeStringView& name) const;

protected:
    std::shared_ptr<AuxiliaryFunctionModules> m_auxiliaryFunctionModules;

#pragma mark - Operation
public:
    typedef std::function<void(InnerDatabase*)> CorruptedNotification;
    bool isFileObservedCorrupted(const UnsafeStringView& path);
    void setNotificationWhenDatabaseCorrupted(const UnsafeStringView& path,
                                              const CorruptedNotification& notification);

protected:
    Optional<bool> migrationShouldBeOperated(const UnsafeStringView& path) override final;
    void backupShouldBeOperated(const UnsafeStringView& path) override final;
    void checkpointShouldBeOperated(const UnsafeStringView& path) override final;
    void integrityShouldBeChecked(const UnsafeStringView& path) override final;
    void purgeShouldBeOperated() override final;

    std::shared_ptr<OperationQueue> m_operationQueue;

#pragma mark - Checkpoint
public:
    void enableAutoCheckpoint(InnerDatabase* database, bool enable);

private:
    std::shared_ptr<Config> m_autoCheckpointConfig;

#pragma mark - Backup
public:
    void enableAutoBackup(InnerDatabase* database, bool enable);

protected:
    std::shared_ptr<Config> m_autoBackupConfig;

#pragma mark - Migration
public:
    void enableAutoMigration(InnerDatabase* database, bool enable);

protected:
    std::shared_ptr<Config> m_autoMigrateConfig;

#pragma mark - Trace
public:
    void setNotificationForSQLGLobalTraced(const ShareableSQLTraceConfig::Notification& notification);
    void setNotificationWhenPerformanceGlobalTraced(
    const ShareablePerformanceTraceConfig::Notification& notification);
    void setNotificationWhenErrorTraced(const Notifier::Callback& notification);
    void setNotificationWhenErrorTraced(const UnsafeStringView& path,
                                        const Notifier::Callback& notification);

protected:
    std::shared_ptr<Config> m_globalSQLTraceConfig;
    std::shared_ptr<Config> m_globalPerformanceTraceConfig;

    void globalLog(int rc, const char* message);

    static void breakpoint() WCDB_USED WCDB_NO_INLINE;
    static void print(const UnsafeStringView& message);

#pragma mark - Merge FTS Index
public:
    using TableArray = OperationQueue::TableArray;
    void enableAutoMergeFTSIndex(InnerDatabase* database, bool enable);
    Optional<bool> mergeFTSIndexShouldBeOperated(const UnsafeStringView& path,
                                                 TableArray newTables,
                                                 TableArray modifiedTables) override final;

protected:
    std::shared_ptr<Config> m_AutoMergeFTSConfig;

#pragma mark - Config
public:
    void setABTestConfig(const UnsafeStringView& configName,
                         const UnsafeStringView& configValue);
    void removeABTestConfig(const UnsafeStringView& configName);
    Optional<UnsafeStringView> getABTestConfig(const UnsafeStringView& configName);

    void setDefaultCipherConfiguration(int version);
    bool setDefaultTemporaryDirectory(const UnsafeStringView& dir);

protected:
    Configs m_configs;
    mutable SharedLock m_memory;
    StringViewMap<StringView> m_abtestConfig;
};

} // namespace WCDB
