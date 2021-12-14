/*
 * Copyright (c) 2021 Argentum Systems Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <drivers/pinmux.h>
#include <soc.h>

static int board_pinmux_init(const struct device *dev)
{
	const struct device *muxa = DEVICE_DT_GET(DT_NODELABEL(pinmux_a));
	const struct device *muxb = DEVICE_DT_GET(DT_NODELABEL(pinmux_b));

	ARG_UNUSED(dev);

	if (!device_is_ready(muxa)) {
		return -ENXIO;
	}
	if (!device_is_ready(muxb)) {
		return -ENXIO;
	}

#if (ATMEL_SAM0_DT_SERCOM_CHECK(0, atmel_sam0_spi) && CONFIG_SPI_SAM0)
	/* SPI SERCOM0 on MISO=PA04/pad 0, MOSI=PA06/pad 2, SCK=PA07/pad 3 */
	pinmux_pin_set(muxa, 4, PINMUX_FUNC_D);
	pinmux_pin_set(muxa, 6, PINMUX_FUNC_D);
	pinmux_pin_set(muxa, 7, PINMUX_FUNC_D);
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(1, atmel_sam0_spi) && CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(2, atmel_sam0_spi) && CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(3, atmel_sam0_spi) && CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_spi) && CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(5, atmel_sam0_spi) && CONFIG_SPI_SAM0)
	/* SPI SERCOM5 on MISO=PB16/pad 0, MOSI=PB22/pad 2, SCK=PB23/pad 3 */
	pinmux_pin_set(muxb, 16, PINMUX_FUNC_C);
	pinmux_pin_set(muxb, 22, PINMUX_FUNC_D);
	pinmux_pin_set(muxb, 23, PINMUX_FUNC_D);
#endif

#if (ATMEL_SAM0_DT_SERCOM_CHECK(0, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(1, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(2, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
	/* SERCOM2 on SDA=PA08, SCL=PA09 */
	pinmux_pin_set(muxa, 8, PINMUX_FUNC_D);
	pinmux_pin_set(muxa, 9, PINMUX_FUNC_D);
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(3, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if (ATMEL_SAM0_DT_SERCOM_CHECK(5, atmel_sam0_i2c) && CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif

#if (ATMEL_SAM0_DT_TCC_CHECK(0, atmel_sam0_tcc_pwm) && CONFIG_PWM_SAM0_TCC)
	/* TCC0 on WO4=PB10 - note WO4 is the inverse of WO0 */
	pinmux_pin_set(muxb, 10, PINMUX_FUNC_F);
#endif

	return 0;
}

SYS_INIT(board_pinmux_init, PRE_KERNEL_2, CONFIG_PINMUX_INIT_PRIORITY);
