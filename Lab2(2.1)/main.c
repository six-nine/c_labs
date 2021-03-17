#include "main.h"

#include <stdio.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.141592
#endif

void print_menu() {
  printf(
      "1. Set ball radius\n"
      "2. Get ball surface area\n"
      "3. Get ball volume\n"
      "4. Get edge of an inscribed tetrahedron\n"
      "5. Get cross-sectional area drawn at a distance of k from the center\n"
      "6. Version and author\n"
      "7. Exit\n");
}

void get_validated_int(int *variable, int min_value, int max_value) {
  int good_input = 0;
  while (!good_input) {
    int result = scanf("%d", &*variable);
    good_input =
        (result == 1 && *variable >= min_value && *variable <= max_value);
    while (getchar() != '\n') {
    }
    if (!good_input) {
      printf("Incorrect input. Try again\n");
    }
  }
}

void get_validated_double(double *variable, double min_value, double max_value,
                          char *message) {
  double good_input = 0;
  while (!good_input) {
    if (strlen(message) != 0) {
      printf("%s", message);
    }
    int result = scanf("%lf", &*variable);
    good_input =
        (result == 1 && *variable >= min_value && *variable <= max_value);
    while (getchar() != '\n') {
    }
    if (!good_input) {
      printf("Incorrect input. Try again\n");
    }
  }
}

void set_ball_radius(double *radius) {
  get_validated_double(radius, 0, 100, "Enter new radius:\n");
}

double get_surface_area(double radius) { return 4 * M_PI * pow(radius, 2); }

double get_volume(double radius) {
  return (double)4 / (double)3 * M_PI * pow(radius, 3);
}

double get_tetradeon(double radius) { return 2 * sqrt((double)2 / 3) * radius; }

double get_cross_sectional_area(double radius, double k) {
  return (pow(radius, 2) - pow(k, 2)) * M_PI;
}

void get_info() { printf("v. 1.0.0\n© Vadim Kozlov, 2021\n"); }

int main() {
  double ball_radius = 0;
  int work = 1;
  while (work) {
    printf("Current ball radius: %f.\n", ball_radius);
    printf("===== MENU =====\n");
    int menu_item;
    double k;
    print_menu();
    get_validated_int(&menu_item, 1, 7);

    switch (menu_item) {
      case 1:
        set_ball_radius(&ball_radius);
        break;
      case 2:
        printf("Surface area: %f\n", get_surface_area(ball_radius));
        break;
      case 3:
        printf("Volume: %f\n", get_volume(ball_radius));
        break;
      case 4:
        printf("Edge of an inscribed tetrahedron: %f\n",
               get_tetradeon(ball_radius));
        break;
      case 5:
        get_validated_double(&k, 0, ball_radius, "Enter k: ");
        printf("Cross-sectional area: %f\n",
               get_cross_sectional_area(ball_radius, k));
        break;
      case 6:
        get_info();
        break;
      case 7:
        work = 0;
        break;
    }
  }

  return 0;
}