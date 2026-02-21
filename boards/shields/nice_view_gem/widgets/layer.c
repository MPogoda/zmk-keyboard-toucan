#include <zephyr/kernel.h>
#include <drivers/behavior.h>
#include <stdio.h>
#include <string.h>

#include "layer.h"
#include "../assets/custom_fonts.h"
#include <zmk/physical_layouts.h>
#include <zmk/keymap.h>
#include <zmk/matrix.h>
#include <zmk/wpm.h>



void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_24, LV_TEXT_ALIGN_CENTER);

    char fallback_layer_name[16]; 

    const char *layer_name = zmk_keymap_layer_name(zmk_keymap_layer_index_to_id(state->layer_index));

    if (layer_name == NULL || layer_name[0] == '\0') {
        sprintf(fallback_layer_name, "L#%" PRIu8, state->layer_index);
        
        layer_name = fallback_layer_name;
    }

    lv_canvas_draw_text(canvas, 0, 70, SCREEN_WIDTH, &label_dsc, layer_name);
}

void draw_wpm_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_CENTER);

    char wpm_str[16];
    snprintf(wpm_str, sizeof(wpm_str), "%d WPM", state->wpm);

    lv_canvas_draw_text(canvas, 0, 110, SCREEN_WIDTH, &label_dsc, wpm_str);
}