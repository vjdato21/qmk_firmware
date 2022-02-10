/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2021 Harrison Chan (Xelus)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "c1.h"

// Manage Windows and Mac LEDs
// - Show status of mode switch
// - Turn LEDs off durring USB suspend
static bool mode_leds_show = true;
static bool mode_leds_windows;

static void mode_leds_update(void){
    writePin(LED_WIN_PIN, mode_leds_show && mode_leds_windows);
    writePin(LED_MAC_PIN, mode_leds_show && !mode_leds_windows);
}

bool dip_switch_update_kb(uint8_t index, bool active){
    if(index == 0) {
        if(active) { // Mac mode
            layer_move(0);
        } else { // Windows mode
            layer_move(2);
        }

        // Update mode and update leds
        mode_leds_windows = !active;
        mode_leds_update();
    }

    dip_switch_update_user(index, active);
    return true;
}

void keyboard_pre_init_kb(void) {
    // Setup Win & Mac LED Pins as output
    setPinOutput(LED_WIN_PIN);
    setPinOutput(LED_MAC_PIN);

    // WORKAROUND: Mac & Windows LED flicker.
    // Normally the GPIOs in DIP_SWITCH_PINS will be initialized by dip_switch_init().
    // But during startup of the keyboard the Mac/Windows dip switch seems to jitter, causing the Mac and Windows LEDs to flicker.
    // Maybe the internal pull-up of this chip is really weak, and needs some time to pullup the input voltage to the high level? Seems unlikely but cannot think of a better explanation.
    // By doing the configuration of the GPIOs here the pullup is enabled earlier and the flicker is gone.
    const pin_t dip_switch_pad[] = DIP_SWITCH_PINS;
    const size_t size = sizeof(dip_switch_pad) / sizeof(dip_switch_pad[0]);
    for (size_t i=0; i<size; i++) {
        setPinInputHigh(dip_switch_pad[i]);
    }

    keyboard_pre_init_user();
}
