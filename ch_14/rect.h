#ifndef RECT_H
#define RECT_H

typedef enum {rectangle, line, point} shape_type;
typedef struct POINT {float x; float y;} point_t;
typedef struct RECT {point_t lo, hi; shape_type shape;} rect_t;
typedef enum {P_IN, P_OUT, P_CORNER, P_LINE, P_CORNER_LO} in_type;
typedef enum {false, true} boolean;

boolean compare_points(float, float);
void switch_pts(float* pt_1, float* pt_2);
rect_t check_edge_cases(rect_t rect);
void print_rect_info(rect_t rect);
rect_t handle_input();
void line_in(rect_t rect, point_t pt);
void pt_in(rect_t rect, point_t pt);
boolean in_or_out(rect_t rect, point_t pt);
void rect_in(rect_t rect, point_t pt);
point_t compare_position(rect_t rect);
boolean compare_lo_point(rect_t rect, point_t pt);
void take_rect_and_pt(void);
#endif
