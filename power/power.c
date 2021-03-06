/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include <hardware/hardware.h>
#include <hardware/power.h>

#define CTRL_FILE "/dev/.tegra-fqd/screen_on"

static void endeavoru_power_init(struct power_module *module) {
}

static void endeavoru_power_set_interactive(struct power_module *module, int on) {
    int fd;

    if(on) {
        fd = open(CTRL_FILE, O_CREAT, S_IRUSR);
        if(fd != -1)
            close(fd);
    }
    else {
        unlink(CTRL_FILE);
    }
}

static void endeavoru_power_hint(struct power_module *module, power_hint_t hint,
                            void *data)
{
    switch (hint) {
    case POWER_HINT_VSYNC:
        break;

    default:
            break;
    }
}

static struct hw_module_methods_t power_module_methods = {
    .open = NULL,
};

struct power_module HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = POWER_MODULE_API_VERSION_0_2,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = POWER_HARDWARE_MODULE_ID,
        .name = "Endeavoru Power HAL",
        .author = "The CyanogenMod Project",
        .methods = &power_module_methods,
    },

    .init = endeavoru_power_init,
    .setInteractive = endeavoru_power_set_interactive,
    .powerHint = endeavoru_power_hint,
};
