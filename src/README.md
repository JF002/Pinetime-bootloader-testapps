# pinetime-bootloader-testapps 
This project builds two basic applications that can be used with pinetime-bootloader.
These applications simply configure a pin as output to light an LED and loop on NOPs.

## How to build

 - Application A : 
    
    `cmake -DARM_NONE_EABI_TOOLCHAIN_PATH="/home/jf/nrf52/gcc-arm-none-eabi-8-2019-q3-update" -DNRFJPROG=/opt/nrfjprog/nrfjprog -DAPP_A=1`

 - Application B:
 
    `cmake -DARM_NONE_EABI_TOOLCHAIN_PATH="/home/jf/nrf52/gcc-arm-none-eabi-8-2019-q3-update" -DNRFJPROG=/opt/nrfjprog/nrfjprog -DAPP_B=1`

## Generate signed image for MCUBoot

 - **First time only** Generate key : `<...>/mcuboot/scripts/imgtool.py keygen -k keys -t rsa-2048`
 - Create image : `/home/jf/nrf52/mcuboot/scripts/imgtool.py create --key keys  --header-size 0x200 --pad-header --align 4 --version 1.0 --slot-size 0x3000 --pad pinetime-bootloader-testapp-a.hex signed_application_a.bin`

## How to flash (using JLinkExe)

Start JLinkExe: `JLinkExe -device nrf52 -if swd -speed 4000 -autoconnect 1`

Type the following command in JLinkExe command prompt:

 - Application A:
 
   `loadbin /home/jf/nrf52/pinetime-testapp/cmake-build-debug/src/signed_application_a.bin 0x60000`
   
 - Application B:
 
   `loadbin /home/jf/nrf52/pinetime-testapp/cmake-build-debug/src/signed_application_b.bin 0x70000`