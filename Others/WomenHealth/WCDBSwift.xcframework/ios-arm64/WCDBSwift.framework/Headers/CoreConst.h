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

namespace WCDB {

#pragma mark - Async Queue
static constexpr const double AsyncQueueTimeOutForExiting = 10.0;

#pragma mark - Operation Queue
static constexpr const char* OperationQueueName = "com.Tencent.WCDB.Queue.Operation";
static constexpr double OperationQueueTimeIntervalForRetringAfterFailure = 5.0;
#pragma mark - Operation Queue - Migration
static constexpr const double OperationQueueTimeIntervalForMigration = 2.0;
static constexpr const int OperationQueueTolerableFailuresForMigration = 5;
#pragma mark - Operation Queue - Purge
static constexpr const double OperationQueueTimeIntervalForPurgingAgain = 30.0;
static constexpr const double OperationQueueRateForTooManyFileDescriptors = 0.7;
#pragma mark - Operation Queue - Checkpoint
static constexpr const double OperationQueueTimeIntervalForCheckpoint = 10.0;
#pragma mark - Operation Queue - Backup
#ifndef WCDB_QUICK_TESTS
static double OperationQueueTimeIntervalForBackup = 600.0;
#else
static double OperationQueueTimeIntervalForBackup = 10.0;
#endif
#pragma mark - Operation Queue - Merge FTS Index
static constexpr const double OperationQueueTimeIntervalForMergeFTSIndex
= 1.871; //Use prime numbers to reduce the probability of collision with external logic

#pragma mark - Config - Auto Checkpoint
static constexpr const char* AutoCheckpointConfigName = "com.Tencent.WCDB.Config.AutoCheckpoint";
#pragma mark - Config - Auto Backup
static constexpr const char* AutoBackupConfigName = "com.Tencent.WCDB.Config.AutoBackup";
#pragma mark - Config - Auto Migrate
static constexpr const char* AutoMigrateConfigName = "com.Tencent.WCDB.Config.AutoMigrate";
#pragma mark - Config - Auto Merge
static constexpr const char* AutoMergeFTSIndexConfigName
= "com.Tencent.WCDB.Config.AutoMergeFTSIndex";
static constexpr const char* AutoMergeFTSIndexQueueName = "com.Tencent.WCDB.Queue.MergeIndex";
static constexpr const int AutoMergeFTS5IndexMinSegmentCount = 4;
static constexpr const double AutoMergeFTSIndexMaxExpectingDuration = 0.02;
static constexpr const double AutoMergeFTSIndexMaxInitializeDuration = 0.005;
#pragma mark - Config - Basic
static constexpr const char* BasicConfigName = "com.Tencent.WCDB.Config.Basic";
static constexpr const int BasicConfigBusyRetryMaxAllowedNumberOfTimes = 3;
#pragma mark - Config - Busy Retry
static constexpr const char* BusyRetryConfigName = "com.Tencent.WCDB.Config.BusyRetry";
static constexpr const double BusyRetryTimeOut = 10.0;
#pragma mark - Config - Cipher
static constexpr const char* CipherConfigName = "com.Tencent.WCDB.Config.Cipher";
static constexpr const int CipherConfigDefaultPageSize = SQLITE_DEFAULT_PAGE_SIZE;
#pragma mark - Config - Global SQL Trace
static constexpr const char* GlobalSQLTraceConfigName = "com.Tencent.WCDB.Config.GlobalSQLTrace";
#pragma mark - Config - Global Performance Trace
static constexpr const char* GlobalPerformanceTraceConfigName
= "com.Tencent.WCDB.Config.GlobalPerformanceTrace";
#pragma mark - Config - Performance Trace
static constexpr const char* PerformanceTraceConfigName
= "com.Tencent.WCDB.Config.PerformanceTrace";
#pragma mark - Config - SQL Trace
static constexpr const char* SQLTraceConfigName = "com.Tencent.WCDB.Config.SQLTrace";
#pragma mark - Config - Tokenize
static constexpr const char* TokenizeConfigPrefix = "com.Tencent.WCDB.Config.Tokenize.";
#pragma mark - Config - AuxiliaryFunction
static constexpr const char* AuxiliaryFunctionConfigPrefix
= "com.Tencent.WCDB.Config.AuxiliaryFunction.";

#pragma mark - Notifier
static constexpr const char* NotifierPreprocessorName = "com.Tencent.WCDB.Notifier.PreprocessTag";
static constexpr const char* NotifierLoggerName = "com.Tencent.WCDB.Notifier.Log";

#pragma mark - Handle Pool
static constexpr const int HandlePoolMaxAllowedNumberOfHandles = 32;
enum HandleSlot : unsigned int {
    HandleSlotNormal = 0,
    HandleSlotMigrating,
    HandleSlotMigrate,
    HandleSlotCheckPoint,
    HandleSlotOperation,
    HandleSlotAssemble,
    HandleSlotCount,
};
enum HandleCategory : unsigned int {
    HandleCategoryNormal = 0,
    HandleCategoryMigrating,
    HandleCategoryMigrate,
    HandleCategoryBackupRead,
    HandleCategoryBackupWrite,
    HandleCategoryCheckpoint,
    HandleCategoryIntegrity,
    HandleCategoryAssemble,
    HandleCategoryCipher,
    HandleCategoryCount,
};
enum class HandleType : unsigned int {
    Normal = (HandleCategoryNormal << 8) | HandleSlotNormal,
    Migrating = (HandleCategoryMigrating << 8) | HandleSlotMigrating,
    Migrate = (HandleCategoryMigrate << 8) | HandleSlotMigrate,
    BackupRead = (HandleCategoryBackupRead << 8) | HandleSlotOperation,
    BackupWrite = (HandleCategoryBackupWrite << 8) | HandleSlotOperation,
    BackupCipher = (HandleCategoryCipher << 8) | HandleSlotOperation,
    Checkpoint = (HandleCategoryCheckpoint << 8) | HandleSlotCheckPoint,
    Integrity = (HandleCategoryIntegrity << 8) | HandleSlotOperation,
    Assemble = (HandleCategoryAssemble << 8) | HandleSlotAssemble,
    AssembleCipher = (HandleCategoryCipher << 8) | HandleSlotAssemble,
    AssembleBackupRead = (HandleCategoryBackupRead << 8) | HandleSlotAssemble,
    AssembleBackupWrite = (HandleCategoryBackupWrite << 8) | HandleSlotAssemble,
};
static constexpr HandleSlot slotOfHandleType(HandleType type)
{
    return HandleSlot(((unsigned int) type) & 0xff);
}
static constexpr HandleCategory categoryOfHandleType(HandleType type)
{
    return HandleCategory(((unsigned int) type >> 8) & 0xff);
}

#pragma mark - Migrate
static constexpr const double MigrateMaxExpectingDuration = 0.01;
static constexpr const double MigrateMaxInitializeDuration = 0.005;

static constexpr const char* ErrorStringKeyType = "Type";
static constexpr const char* ErrorStringKeySource = "Source";

#define WCDB_ERROR_STRING_KEY_PATH "Path"
static constexpr const char* ErrorStringKeyPath = WCDB_ERROR_STRING_KEY_PATH;

#define WCDB_ERROR_STRING_KEY_ASSOCIATE_PATH "AssociatePath"
static constexpr const char* ErrorStringKeyAssociatePath = WCDB_ERROR_STRING_KEY_ASSOCIATE_PATH;

#define WCDB_ERROR_STRING_KEY_SQL "SQL"
static constexpr const char* ErrorStringKeySQL = WCDB_ERROR_STRING_KEY_SQL;

#define WCDB_ERROR_INT_KEY_TAG "Tag"
static constexpr const char* ErrorIntKeyTag = WCDB_ERROR_INT_KEY_TAG;

#define WCDB_ERROR_INT_KEY_EXTCODE "ExtCode"
static constexpr const char* ErrorIntKeyExtCode = WCDB_ERROR_INT_KEY_EXTCODE;

#pragma mark - Error - Source
static constexpr const char* ErrorSourceSQLite = "SQLite";
static constexpr const char* ErrorSourceRepair = "Repair";
static constexpr const char* ErrorSourceSystem = "System";
static constexpr const char* ErrorSourceAssertion = "Assertion";
static constexpr const char* ErrorSourceNative = "Native";
static constexpr const char* ErrorSourceSwift = "Swift";

#pragma mark - Error - Type
static constexpr const char* ErrorTypeMigrate = "Migrate";
static constexpr const char* ErrorTypeCheckpoint = "Checkpoint";
static constexpr const char* ErrorTypeIntegrity = "Integrity";
static constexpr const char* ErrorTypeBackup = "Backup";
static constexpr const char* ErrorTypeAssemble = "Assemble";
static constexpr const char* ErrorTypeMergeIndex = "MergeIndex";

#pragma mark - Tag
static constexpr const int TagInvalidValue = 0;

#pragma mark - Constraint
static_assert(OperationQueueTimeIntervalForMigration > MigrateMaxExpectingDuration, "");

} // namespace WCDB
