//
// Created by qiuwenchen on 2022/9/15.
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

#include "Macro.h"

#pragma mark - errno

#ifndef EAUTH
// Magic number, something unique to avoid being matched
#define EAUTH 1550442950 //0x5c69e1c6
#endif

#pragma mark - mman

#if defined(__linux__) || defined(__ANDROID__)
#ifndef MAP_NOEXTEND
// Not exists in Linux, set to 0 to avoid making a difference in OR operation
#define MAP_NOEXTEND 0x0
#endif /* ndef MAP_NOEXTEND */
#endif /* defined(__linux__) || defined(__ANDROID__) */

#pragma mark - pthread

#ifndef _WIN32
#include <pthread.h>
#endif

#if defined(__linux__) || defined(__ANDROID__)

WCDB_EXTERN_C_BEGIN
int pthread_main_np();
WCDB_EXTERN_C_END
#define pthread_setname_np(CHAR) pthread_setname_np(pthread_self(), CHAR)

#endif /* defined(_linux__) || defined(__ANDROID__) */

#pragma mark - stat

#ifndef _WIN32
#define StatType struct stat
#define StatFunc stat
#else
#define StatType struct _stat64
#define StatFunc _stat64
#endif

#if defined(__linux__) || defined(__ANDROID__)
#define st_atimespec st_atim
#define st_mtimespec st_mtim
#define st_ctimespec st_ctim
#elif defined(_WIN32)
#define st_atimespec st_atime
#define st_mtimespec st_mtime
#define st_ctimespec st_ctime
#endif

#pragma mark - uinstd

#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#endif

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifdef __ANDROID__
WCDB_EXTERN_C_BEGIN
int getdtablesize();
WCDB_EXTERN_C_END
#endif /* __ANDROID__ */

#ifdef _WIN32
#define FileFullAccess S_IREAD | S_IWRITE
#define lseek _lseeki64
#define DirFullAccess 0
#define mkdir(path, mask) _mkdir(path)
#else
#define FileFullAccess S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define DirFullAccess S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH
#endif //_WIN32

#pragma mark - string

#ifdef _WIN32
#define strncasecmp _strnicmp
#endif //_WIN32
