# Ubiquitous Fiesta

STM32H753ZI project demonstrating **LED control with UART commands** using **HAL libraries**.  

---

## Project Description

This project implements a **state machine for an LED** with 4 states:

| State  | Behavior                                                                 |
|--------|-------------------------------------------------------------------------|
| **OFF**  | LED is off                                                             |
| **ON**   | LED is on; UART sends a message from the circular buffer about state  |
| **FAST** | LED blinks at 1-second intervals; UART sends state messages           |
| **SLOW** | LED blinks at 5-second intervals; UART sends state messages           |

The **user can send commands over UART** to change the LED state.  
UART communication and LED blinking are handled using **interrupts** and **timer-based processing**.

---

## Knowledge Areas Covered

- GPIO configuration and digital output  
- Circular buffer implementation  
- Clock setup for peripherals  
- UART communication with interrupts  
- Timer-based processing  
- Interrupt handling  

---

## Pin Configuration

| Peripheral  | Pin       |
|------------|-----------|
| LED        | `PG1`   |
| UART TX    | `PA9` |
| UART RX    | `PA10` |
| GND        | GND       |
| User Button| `PC13`    |

---

## Usage

1. Build the project in **STM32CubeIDE**.  
2. Flash to the **STM32H753ZI** board.  
3. Open a **UART terminal** at the configured baud rate (e.g., 115200).  
4. Send commands to control the LED:

| Command | LED State |
|---------|-----------|
| `0`     | OFF       |
| `1`     | ON        |
| `2`     | FAST      |
| `3`     | SLOW      |

---

## Example UART Commands

```text
> 1
LED State: ON
> 2
LED State: FAST
> 0
LED State: OFF
