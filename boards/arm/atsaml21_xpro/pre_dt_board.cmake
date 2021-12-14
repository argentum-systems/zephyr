# Copyright (c) 2021 Argentum Systems Ltd.
# SPDX-License-Identifier: Apache-2.0

# Suppress "unique_unit_address_if_enabled" to handle the following overlaps:
# - /soc/pinmux@40002800 & /soc/gpio@40002800
# - /soc/pinmux@40002880 & /soc/gpio@40002880
list(APPEND EXTRA_DTC_FLAGS "-Wno-unique_unit_address_if_enabled")
