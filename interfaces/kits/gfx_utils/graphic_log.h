/*
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GRAPHIC_LITE_GRAPHIC_LOG_H
#define GRAPHIC_LITE_GRAPHIC_LOG_H

#include "graphic_config.h"

#if ENABLE_GRAPHIC_LOG
#ifdef __LITEOS_M__
#include "log.h"
#ifndef HILOG_DEBUG
#define HILOG_DEBUG(mod, format, ...)
#endif // HILOG_DEBUG
#ifndef HILOG_ERROR
#define HILOG_ERROR(mod, format, ...)
#endif // HILOG_ERROR
#ifndef HILOG_FATAL
#define HILOG_FATAL(mod, format, ...)
#endif // HILOG_FATAL
#ifndef HILOG_INFO
#define HILOG_INFO(mod, format, ...)
#endif // HILOG_INFO
#ifndef HILOG_WARN
#define HILOG_WARN(mod, format, ...)
#endif // HILOG_WARN
#elif defined __LITEOS_A__ || defined __linux__
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_DOMAIN 0xD001400
#define LOG_TAG "GRAPHIC"
#include "log.h"
#else
#include <stdio.h>
#ifndef HILOG_FATAL
#define HILOG_FATAL(mod, ...)                                   \
do {                                                            \
    printf("[FATAL]: %s\n", __VA_ARGS__);                       \
    fflush(stdout);                                             \
} while (0)
#endif // HILOG_FATAL
#ifndef HILOG_ERROR
#define HILOG_ERROR(mod, ...)                                   \
do {                                                            \
    printf("[ERROR]: %s\n", __VA_ARGS__);                       \
    fflush(stdout);                                             \
} while (0)
#endif // HILOG_ERROR
#ifndef HILOG_INFO
#define HILOG_INFO(mod, ...)                                    \
do {                                                            \
    printf("[INFO]: %s\n", __VA_ARGS__);                        \
    fflush(stdout);                                             \
} while (0)
#endif // HILOG_INFO
#ifndef HILOG_WARN
#define HILOG_WARN(mod, ...)                                    \
do {                                                            \
    printf("[WARN]: %s\n", __VA_ARGS__);                        \
    fflush(stdout);                                             \
} while (0)
#endif // HILOG_WARN
#ifndef HILOG_DEBUG
#define HILOG_DEBUG(mod, ...)                                   \
do {                                                            \
    printf("[DEBUG]: %s\n", __VA_ARGS__);                       \
    fflush(stdout);                                             \
} while (0)
#endif // HILOG_DEBUG
#endif // __LITEOS_M__
#else
#ifndef HILOG_FATAL
#define HILOG_FATAL(mod, ...)
#endif // HILOG_FATAL
#ifndef HILOG_ERROR
#define HILOG_ERROR(mod, ...)
#endif // HILOG_ERROR
#ifndef HILOG_INFO
#define HILOG_INFO(mod, ...)
#endif // HILOG_INFO
#ifndef HILOG_WARN
#define HILOG_WARN(mod, ...)
#endif // HILOG_WARN
#ifndef HILOG_DEBUG
#define HILOG_DEBUG(mod, ...)
#endif // HILOG_DEBUG
#endif // ENABLE_GRAPHIC_LOG
#endif // GRAPHIC_LITE_GRAPHIC_LOG_H
