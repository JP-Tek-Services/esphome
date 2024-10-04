#include "es8388_component.h"
#include "esphome/core/hal.h"

#include <soc/io_mux_reg.h>

namespace esphome {
namespace es8388 {

void ES8388Component::setup() {
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
  WRITE_PERI_REG(PIN_CTRL, READ_PERI_REG(PIN_CTRL) & 0xFFFFFFF0);

  // mute
  // this->write_byte(0x19, 0x04); //ES8388_DACCONTROL3
  // // powerup
  // this->write_byte(0x01, 0x50); //ES8388_CONTROL2
  // this->write_byte(0x02, 0x00); //ES8388_CHIPPOWER
  // // worker mode
  // this->write_byte(0x08, 0x00); //ES8388_MASTERMODE
  // // DAC powerdown
  // // this->write_byte(0x04, 0xC0);
  // this->write_byte(0x04, 0x3e); //ES8388_DACPOWER
  // // vmidsel/500k ADC/DAC idem
  // this->write_byte(0x00, 0x12); //ES8388_CONTROL1

  // // i2s 16 bits
  // this->write_byte(0x17, 0x18); //ES8388_DACCONTROL1
  // // sample freq 256
  // this->write_byte(0x18, 0x02); //ES8388_DACCONTROL2
  // // LIN2/RIN2 for mixer
  // // this->write_byte(0x26, 0x00); //ES8388_DACCONTROL16
  // this->write_byte(0x26, 0x1B); //ES8388_DACCONTROL16
  // // left DAC to left mixer
  // this->write_byte(0x27, 0x90); //ES8388_DACCONTROL17
  // // right DAC to right mixer
  // this->write_byte(0x2A, 0x90); //ES8388_DACCONTROL20
  // // DACLRC ADCLRC idem
  // this->write_byte(0x2B, 0x80); //ES8388_DACCONTROL21
  // this->write_byte(0x2D, 0x00); //ES8388_DACCONTROL23
  // // DAC volume max
  // this->write_byte(0x1B, 0x00); //ES8388_DACCONTROL5
  // this->write_byte(0x1A, 0x00); //ES8388_DACCONTROL4

  // // ADC poweroff
  // this->write_byte(0x03, 0xFF); //ES8388_ADCPOWER
  // // ADC amp 24dB
  // this->write_byte(0x09, 0x88); //ES8388_ADCCONTROL1
  // // LINPUT1/RINPUT1
  // this->write_byte(0x0A, 0x00); //ES8388_ADCCONTROL2
  // // ADC mono left
  // this->write_byte(0x0B, 0x02); //ES8388_ADCCONTROL3
  // // i2S 16b
  // this->write_byte(0x0C, 0x0C); //ES8388_ADCCONTROL4
  // // MCLK 256
  // this->write_byte(0x0D, 0x02); //ES8388_ADCCONTROL5
  // // ADC Volume
  // this->write_byte(0x10, 0x00); //ES8388_ADCCONTROL8
  // this->write_byte(0x11, 0x00); //ES8388_ADCCONTROL9
  // // ALC OFF
  // this->write_byte(0x03, 0x09); //ES8388_ADCPOWER
  // this->write_byte(0x2B, 0x80); //ES8388_DACCONTROL21

  // this->write_byte(0x02, 0xF0); //ES8388_CHIPPOWER
  // delay(1);
  // this->write_byte(0x02, 0x00); //ES8388_CHIPPOWER
  // // DAC power-up LOUT1/ROUT1 enabled
  // // this->write_byte(0x04, 0x30); //ES8388_DACPOWER
  // this->write_byte(0x04, 0x3e); //ES8388_DACPOWER
  // this->write_byte(0x03, 0x00); //ES8388_ADCPOWER
  // // set LOUT1 / ROUT1 volume max
  // this->write_byte(0x2E, 0x1C); //ES8388_DACCONTROL24
  // this->write_byte(0x2F, 0x1C); //ES8388_DACCONTROL25
  // // set LOUT2 / ROUT2 volume max
  // this->write_byte(0x30, 0x1C); //ES8388_DACCONTROL26
  // this->write_byte(0x31, 0x1C); //ES8388_DACCONTROL27
  // // unmute
  // this->write_byte(0x19, 0x00); //ES8388_DACCONTROL3
    /* mute DAC during setup, power up all systems, slave mode */

  #define ES8388_CONTROL1 0x00
  #define ES8388_CONTROL2 0x01
  #define ES8388_CHIPPOWER 0x02
  #define ES8388_ADCPOWER 0x03
  #define ES8388_DACPOWER 0x04
  #define ES8388_CHIPLOPOW1 0x05
  #define ES8388_CHIPLOPOW2 0x06
  #define ES8388_ANAVOLMANAG 0x07
  #define ES8388_MASTERMODE 0x08

  /* ADC */
  #define ES8388_ADCCONTROL1 0x09
  #define ES8388_ADCCONTROL2 0x0a
  #define ES8388_ADCCONTROL3 0x0b
  #define ES8388_ADCCONTROL4 0x0c
  #define ES8388_ADCCONTROL5 0x0d
  #define ES8388_ADCCONTROL6 0x0e
  #define ES8388_ADCCONTROL7 0x0f
  #define ES8388_ADCCONTROL8 0x10
  #define ES8388_ADCCONTROL9 0x11
  #define ES8388_ADCCONTROL10 0x12
  #define ES8388_ADCCONTROL11 0x13
  #define ES8388_ADCCONTROL12 0x14
  #define ES8388_ADCCONTROL13 0x15
  #define ES8388_ADCCONTROL14 0x16

  /* DAC */
  #define ES8388_DACCONTROL1 0x17
  #define ES8388_DACCONTROL2 0x18
  #define ES8388_DACCONTROL3 0x19
  #define ES8388_DACCONTROL4 0x1a
  #define ES8388_DACCONTROL5 0x1b
  #define ES8388_DACCONTROL6 0x1c
  #define ES8388_DACCONTROL7 0x1d
  #define ES8388_DACCONTROL8 0x1e
  #define ES8388_DACCONTROL9 0x1f
  #define ES8388_DACCONTROL10 0x20
  #define ES8388_DACCONTROL11 0x21
  #define ES8388_DACCONTROL12 0x22
  #define ES8388_DACCONTROL13 0x23
  #define ES8388_DACCONTROL14 0x24
  #define ES8388_DACCONTROL15 0x25
  #define ES8388_DACCONTROL16 0x26
  #define ES8388_DACCONTROL17 0x27
  #define ES8388_DACCONTROL18 0x28
  #define ES8388_DACCONTROL19 0x29
  #define ES8388_DACCONTROL20 0x2a
  #define ES8388_DACCONTROL21 0x2b
  #define ES8388_DACCONTROL22 0x2c
  #define ES8388_DACCONTROL23 0x2d
  #define ES8388_DACCONTROL24 0x2e
  #define ES8388_DACCONTROL25 0x2f
  #define ES8388_DACCONTROL26 0x30
  #define ES8388_DACCONTROL27 0x31
  #define ES8388_DACCONTROL28 0x32
  #define ES8388_DACCONTROL29 0x33
  #define ES8388_DACCONTROL30 0x34
  
  this->write_byte(ES8388_DACCONTROL3, 0x04); /* 0x19 */
  this->write_byte(ES8388_CONTROL2, 0x50); /*  */
  this->write_byte(ES8388_CHIPPOWER, 0x00); /*  */
  this->write_byte(ES8388_MASTERMODE, 0x00); /*  */

  /* power up DAC and enable LOUT1+2 / ROUT1+2, ADC sample rate = DAC sample rate */
  this->write_byte(ES8388_DACPOWER, 0x3e); /*  */
  this->write_byte(ES8388_CONTROL1, 0x12); /*  */

  /* DAC I2S setup: 16 bit word length, I2S format; MCLK / Fs = 256*/
  this->write_byte(ES8388_DACCONTROL1, 0x18); /*  */
  this->write_byte(ES8388_DACCONTROL2, 0x02); /*  */

  /* DAC to output route mixer configuration: ADC MIX TO OUTPUT */
  this->write_byte(ES8388_DACCONTROL16, 0x1B); /*  */
  this->write_byte(ES8388_DACCONTROL17, 0x90); /*  */
  this->write_byte(ES8388_DACCONTROL20, 0x90); /*  */

  /* DAC and ADC use same LRCK, enable MCLK input; output resistance setup */
  this->write_byte(ES8388_DACCONTROL21, 0x80); /*  */
  this->write_byte(ES8388_DACCONTROL23, 0x00); /*  */

  /* DAC volume control: 0dB (maximum, unattented)  */
  this->write_byte(ES8388_DACCONTROL5, 0x00); /*  */
  this->write_byte(ES8388_DACCONTROL4, 0x00); /*  */

  /* power down ADC while configuring; volume: +9dB for both channels */
  this->write_byte(ES8388_ADCPOWER, 0xff); /*  */
  this->write_byte(ES8388_ADCCONTROL1, 0x88);  /*  */ // +24db

  /* select LINPUT2 / RINPUT2 as ADC input; stereo; 16 bit word length, format right-justified, MCLK / Fs = 256 */
  this->write_byte(ES8388_ADCCONTROL2, 0xf0);  /*  */ // 50
  this->write_byte(ES8388_ADCCONTROL3, 0x80);  /*  */ // 00
  this->write_byte(ES8388_ADCCONTROL4, 0x0e); /*  */
  this->write_byte(ES8388_ADCCONTROL5, 0x02); /*  */

  /* set ADC volume */
  this->write_byte(ES8388_ADCCONTROL8, 0x20); /*  */
  this->write_byte(ES8388_ADCCONTROL9, 0x20); /*  */

  /* set LOUT1 / ROUT1 volume: 0dB (unattenuated) */
  this->write_byte(ES8388_DACCONTROL24, 0x1e); /*  */
  this->write_byte(ES8388_DACCONTROL25, 0x1e); /*  */

  /* set LOUT2 / ROUT2 volume: 0dB (unattenuated) */
  this->write_byte(ES8388_DACCONTROL26, 0x1e); /*  */
  this->write_byte(ES8388_DACCONTROL27, 0x1e); /*  */

  /* power up and enable DAC; power up ADC (no MIC bias) */
  this->write_byte(ES8388_DACPOWER, 0x3c); /*  */
  this->write_byte(ES8388_DACCONTROL3, 0x00); /*  */
  this->write_byte(ES8388_ADCPOWER, 0x00); /*  */
}

}  // namespace es8388
}  // namespace esphome
