# Clock Driver – My Understanding (STM32)

This document contains my **understanding** of the clock system in STM32 MCUs.

---

## Clock Sources

There are mainly **two types of clock sources** in STM32.

### 1. Internal Clock (HSI / Internal RCC)

- Generated inside the MCU using an RC oscillator
- Starts **very fast** after reset
- **Not very accurate**
- Clock frequency can **drift** with temperature and voltage changes

Because it starts quickly and is always available, the internal clock is used:
- Just after reset
- For reset handling and startup
- As a default / fallback clock source

---

### 2. External Clock (HSE / Crystal)

- Comes from an external crystal or oscillator
- **More accurate and stable** than internal RC
- Takes **time to start and stabilize**
- Usually has a **lower base frequency**

Since the external crystal frequency is low, it is usually given to a **PLL (Phase Locked Loop)** to increase the frequency to the required CPU/system clock.

---

## RCC (Reset and Clock Control)

STM32 has an **RCC (Reset and Clock Control)** block.

RCC is responsible for:
- Selecting the clock source (HSI / HSE / PLL)
- Enabling and disabling clocks for peripherals
- Resetting peripherals and clock logic

RCC takes the clock from HSI or HSE and distributes it to the CPU and peripherals through the clock tree.

---

## Peripheral Clock Gating

After reset, **most peripheral clocks are disabled by default**.

Each peripheral has a clock enable bit inside RCC.
Only when this bit is enabled will the clock reach that peripheral.

Clock gating is done to:
- Save power
- Prevent accidental peripheral usage
- Keep unused peripherals inactive

---

## Why Enabling Peripheral Clock Is Mandatory in Drivers

While writing a driver, **enabling the peripheral clock is the first step**.

Peripheral registers are implemented using **flip-flops**.
Flip-flops work **only when clock is present**.

If the peripheral clock is disabled:
- Software writes to registers will not affect the hardware
- Register configuration will not take effect
- Peripheral will not function even if code looks correct

So, without enabling the clock in RCC, register read/write is basically useless.

---

## Reset Behavior

During a **hardware reset**:
- RCC configuration goes back to default
- Peripheral hardware gets reset
- Registers load reset values (or undefined values as per datasheet)

Because of this, drivers should:
- Not assume any previous register state
- Always configure registers after reset
- Enable clocks and release resets explicitly




