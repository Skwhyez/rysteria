// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Client/Assets/Render.h>
#include <Client/Renderer/Renderer.h>
#include <math.h>

#define PI 3.14159265358979323846

// Draws an arc segment between start_angle and end_angle around (cx, cy)
static void rr_renderer_arc_segment(struct rr_renderer *renderer, float cx, float cy,
                                    float radius, float start_angle, float end_angle) {
    const int steps = 30;  // Number of segments for smoothness
    float angle_step = (end_angle - start_angle) / steps;

    rr_renderer_move_to(renderer, cx, cy);  // Move to center
    rr_renderer_line_to(renderer, cx + radius * cosf(start_angle), cy + radius * sinf(start_angle));

    for (int i = 1; i <= steps; ++i) {
        float angle = start_angle + i * angle_step;
        rr_renderer_line_to(renderer, cx + radius * cosf(angle), cy + radius * sinf(angle));
    }

    rr_renderer_line_to(renderer, cx, cy);  // Close back to center
}

void rr_whirlpool_outer_draw(struct rr_renderer *renderer) {
    rr_renderer_begin_path(renderer);
    rr_renderer_arc_segment(renderer, 0.0f, 0.0f, 40.0f, PI * 0.2f, PI * 1.8f);
    rr_renderer_set_fill(renderer, 0xFF3A8DFF);  // Light blue
    rr_renderer_fill(renderer);
}

void rr_whirlpool_middle_draw(struct rr_renderer *renderer) {
    rr_renderer_begin_path(renderer);
    rr_renderer_arc_segment(renderer, 0.0f, 0.0f, 28.0f, PI * 0.5f, PI * 2.1f);
    rr_renderer_set_fill(renderer, 0xFF1B4F72);  // Darker blue
    rr_renderer_fill(renderer);
}

void rr_whirlpool_inner_draw(struct rr_renderer *renderer) {
    rr_renderer_begin_path(renderer);
    rr_renderer_arc_segment(renderer, 0.0f, 0.0f, 18.0f, PI * 0.8f, PI * 2.5f);
    rr_renderer_set_fill(renderer, 0xFF3A8DFF);  // Light blue inner swirl
    rr_renderer_fill(renderer);

    // White core circle
    rr_renderer_begin_path(renderer);
    rr_renderer_arc(renderer, 0.0f, 0.0f, 5.0f);
    rr_renderer_set_fill(renderer, 0xFFFFFFFF);
    rr_renderer_fill(renderer);
}
