/*
 * Copyright (c) 2021 Argentum Systems Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _ATMEL_SAM_ADC_FIXUP_SAML21_H_
#define _ATMEL_SAM_ADC_FIXUP_SAML21_H_

#define ADC_REFCTRL_REFSEL_VDD_1_2 ADC_REFCTRL_REFSEL_INTVCC1
#define ADC_REFCTRL_REFSEL_VDD_1   ADC_REFCTRL_REFSEL_INTVCC2

#define ADC_SAM0_REFERENCE_ENABLE_PROTECTED

#include "adc_fixup_sam0.h"

#endif /* _ATMEL_SAM_ADC_FIXUP_SAML21_H_ */
