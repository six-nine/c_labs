#ifndef MAIN_H
#define MAIN_H

void get_validated_int(int *variable, int min_value, int max_value);
void get_validated_double(double *variable, double min_value, double max_value,
                          char *message);

void set_ball_radius(double *radius);
double get_surface_area(double radius);
double get_volume(double radius);
double get_tetradeon(double radius);
double get_cross_sectional_area(double radius, double k);
void get_info();

#endif