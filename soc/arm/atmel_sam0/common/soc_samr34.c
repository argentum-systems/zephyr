/*
 * Copyright (c) 2021 Argentum Systems Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <drivers/gpio.h>
#include <drivers/pinmux.h>
#include <soc.h>

static int soc_pinmux_init(const struct device *dev)
{
	const struct device *muxb = DEVICE_DT_GET(DT_NODELABEL(pinmux_b));
	const struct device *muxc = DEVICE_DT_GET(DT_NODELABEL(pinmux_c));

	ARG_UNUSED(dev);

	if (!device_is_ready(muxb)) {
		return -ENXIO;
	}
	if (!device_is_ready(muxc)) {
		return -ENXIO;
	}

#if (ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_spi) && CONFIG_SPI_SAM0)
	pinmux_pin_set(muxb, 30, PINMUX_FUNC_F);
	pinmux_pin_set(muxb, 31, PINMUX_FUNC_F);
	pinmux_pin_set(muxc, 18, PINMUX_FUNC_F);
	pinmux_pin_set(muxc, 19, PINMUX_FUNC_F);
#else
	/* When not in use, it's important that #CS is set high, to avoid
	 * unexpected behavior and increased current consumption... see
	 * Chapter 10 of DS70005356C. We also hold the radio in reset.
	 */
	gpio_pin_configure(muxb, 31, GPIO_OUTPUT_HIGH);
	gpio_pin_configure(muxb, 15, GPIO_OUTPUT_LOW);
#endif

	return 0;
}

SYS_INIT(soc_pinmux_init, PRE_KERNEL_2, CONFIG_PINMUX_INIT_PRIORITY);
