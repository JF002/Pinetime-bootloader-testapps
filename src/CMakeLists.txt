cmake_minimum_required(VERSION 3.10)

project(pinetime-bootloader-testapps C CXX ASM)



# define some variables just for this example to determine file locations
set(NRF_PROJECT_NAME pinetime-bootloader-testapps)
set(NRF_BOARD pca10040)
#set(NRF_SOFTDEVICE s132)

nRF5x_toolchainSetup()
nRF5x_setup()

#nRF5x_addAppScheduler()
#nRF5x_addAppFIFO()
#nRF5x_addAppTimer()
#nRF5x_addAppUART()
#nRF5x_addAppButton()
#nRF5x_addBSP(FALSE FALSE FALSE)
#nRF5x_addAppGpiote()
#nRF5x_addBLEGATT()
#
#nRF5x_addBLEService(ble_lbs)

add_definitions(-DCONFIG_GPIO_AS_PINRESET)
add_definitions(-DDEBUG)


include_directories(.)

set(STARTUP_SOURCE_FILES
  startup/gcc_startup_nrf52.S
  startup/system_nrf52.c
  startup/system_nrf52.h
  startup/nrf.h
  startup/nrf52.h
  startup/nrf52_bitfields.h
  startup/nrf51_to_nrf52.h
  startup/nrf52_name_change.h
  startup/compiler_abstraction.h
  )

list(APPEND SOURCE_FILES
  ${STARTUP_SOURCE_FILES}


  segger_rtt/SEGGER_RTT.c
  segger_rtt/SEGGER_RTT_Syscalls_GCC.c
  segger_rtt/SEGGER_RTT_printf.c

  main.c
  nrf52_nvmc.h
  nrf52_nvmc.c
)

set(INCLUDE_FILES

)

include_directories(
  startup/cmsis/include

)

link_directories(
  ./
)



nRF5x_addExecutable(${APPNAME} "${SOURCE_FILES}" ${INCLUDE_FILES})
