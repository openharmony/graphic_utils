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

#include "hal_cpu.h"
#ifdef _WIN32
#include <windows.h>
#elif defined __LINUX__
#include <unistd.h>
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

uint32_t HalGetCpuCoreNum()
{
    static uint32_t cpuCoreNum = 0;
    if (cpuCoreNum) {
        return cpuCoreNum;
    }
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    cpuCoreNum = sysInfo.dwNumberOfProcessors;
#elif defined __LINUX__
    cpuCoreNum = sysconf(_SC_NPROCESSORS_ONLN);
#elif ((defined (HAL_CPU_NUM)) && (HAL_CPU_NUM < 8))
    cpuCoreNum = HAL_CPU_NUM;
#else
    cpuCoreNum = 1;
#endif
    return cpuCoreNum;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
