// Copyright 2023 Huda Sajjad
#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct {
  unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));

arr_t store_byte_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] = {  // double_word0     double_word1
    {0x00000000000000EF, 0x0000000000000000},
    {0x000000000000BE00, 0x0000000000000000},
    {0x0000000000AD0000, 0x0000000000000000},
    {0x00000000DE000000, 0x0000000000000000},
    {0x000000EF00000000, 0x0000000000000000},
    {0x0000BE0000000000, 0x0000000000000000},
    {0x00AD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000}};

arr_t store_half_word_expected_data[8] = {
    {0x000000000000BEEF, 0x0000000000000000},
    {0x0000000000ADBE00, 0x0000000000000000},
    {0x00000000DEAD0000, 0x0000000000000000},
    {0x000000EFDE000000, 0x0000000000000000},
    {0x0000BEEF00000000, 0x0000000000000000},
    {0x00ADBE0000000000, 0x0000000000000000},
    {0xDEAD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x00000000000000EF}};

arr_t store_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_word_expected_data[8] = {{0x00000000DEADBEEF, 0x0000000000000000},
                                     {0x000000DEADBEEF00, 0x0000000000000000},
                                     {0x0000DEADBEEF0000, 0x0000000000000000},
                                     {0x00DEADBEEF000000, 0x0000000000000000},
                                     {0xF00DC0DE00000000, 0x0000000000000000},
                                     {0x0DC0DE0000000000, 0x00000000000000F0},
                                     {0xC0DE000000000000, 0x000000000000F00D},
                                     {0xDE00000000000000, 0x0000000000F00DC0}};

arr_t store_double_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000}};

arr_t store_double_word_expected_data[8] = {
    {0xDEADBEEFF00DC0DE, 0x0000000000000000},
    {0xADBEEFF00DC0DE00, 0x00000000000000DE},
    {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
    {0xEFF00DC0DE000000, 0x0000000000DEADBE},
    {0xF00DC0DE00000000, 0x00000000DEADBEEF},
    {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
    {0xC0DE000000000000, 0x0000DEADBEEFF00D},
    {0xDE00000000000000, 0x00DEADBEEFF00DC0}};

int store_byte_test() {
  // EF, BE, AD, DE, EF, BE, AD, DE
  unsigned long temp_arr[8] = {0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE};
  int c = 0;
  for (int i = 0; i < 8; i++) {
    (store_byte_data + i)->double_word[0] =
        ((store_byte_data + i)->double_word[0] >> c) | temp_arr[i];
    (store_byte_data + i)->double_word[0] =
        (store_byte_data + i)->double_word[0] << c;

    c = c + 8;
  }

  int check = 1;

  for (int i = 0; i < 8; i++) {
    if ((store_byte_data + i)->double_word[0] ^
        (store_byte_expected_data + i)->double_word[0]) {
      printf("%s", "mismatch in store_byte_data at index:");
      printf("%i", i);
      printf("%s\n", "0");
      check = 0;
    }
    if ((store_byte_data + i)->double_word[1] ^
        (store_byte_expected_data + i)->double_word[1]) {
      printf("%s", "mismatch in store_byte_data at index:");
      printf("%i", i);
      printf("%s\n", "1");
      check = 0;
    }
  }
  return check;
}  // store_byte_test

int store_half_word_test() {
  // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
  unsigned long long temp_arr[8] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE,
                                    0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};
  int c = 0;
  for (int i = 0; i < 8; i++) {
    if (c == 56) {
      (store_half_word_data + i)->double_word[1] =
          (store_half_word_data + i)->double_word[1] | (temp_arr[i] >> 8);
    }
    (store_half_word_data + i)->double_word[0] =
        ((store_half_word_data + i)->double_word[0] >> c) | temp_arr[i];
    (store_half_word_data + i)->double_word[0] = (store_half_word_data + i)->double_word[0]
                                           << c;

    c = c + 8;
  }

  int check = 1;

  for (int i = 0; i < 8; i++) {
    if ((store_half_word_data + i)->double_word[0] ^
        (store_half_word_expected_data +i)->double_word[0]) {
      printf("%s", "mismatch in store_half_word_data at index:");
      printf("%i", i);
      printf("%s\n", "0");
      check = 0;
    }
    if ((store_half_word_data + i)->double_word[1] ^
        (store_half_word_expected_data +i)->double_word[1]) {
      printf("%s", "mismatch in store_half_word_data at index:");
      printf("%i", i);
      printf("%s\n", "1");
      check = 0;
    }
  }
  return check;
}  // store_half_word_test

int store_word_test() {
  // DEADBEEF, F00DC0DE
  unsigned long long temp_arr[2] = {0xDEADBEEF, 0xF00DC0DE};
  int c = 0;
  int of = 24;
  for (int i = 0; i < 8; i++) {
    if (c >= 40) {
      if (i >= 4) {
        (store_word_data + i)->double_word[1] =
            (store_word_data + i)->double_word[1] | (temp_arr[1] >> of);
      } else {
        (store_word_data + i)->double_word[1] =
            (store_word_data + i)->double_word[1] | (temp_arr[0] >> of);
      }
      of = of - 8;
    }
    if (i >= 4) {
      (store_word_data + i)->double_word[0] =
          ((store_word_data + i)->double_word[0] >> c) | temp_arr[1];
      (store_word_data + i)->double_word[0] = (store_word_data + i)->double_word[0] << c;
    } else {
      (store_word_data + i)->double_word[0] =
          ((store_word_data + i)->double_word[0] >> c) | temp_arr[0];
      (store_word_data +i)->double_word[0] = (store_word_data + i)->double_word[0] << c;
    }

    c = c + 8;
  }

  int check = 1;

  for (int i = 0; i < 8; i++) {
    if ((store_word_data + i)->double_word[0] ^
        (store_word_expected_data +i)->double_word[0]) {
      printf("%s", "mismatch in store_word_data at index:");
      printf("%i", i);
      printf("%s\n", "0");
      check = 0;
    }
    if ((store_word_data + i)->double_word[1] ^
        (store_word_expected_data +i)->double_word[1]) {
      printf("%s", "mismatch in store_word_data at index:");
      printf("%i", i);
      printf("%s\n", "1");
      check = 0;
    }
  }
  return check;
}  // store_word_test

int store_double_word_test() {
  // DEADBEEFF00DC0DE
  unsigned long long temp_arr = 0xDEADBEEFF00DC0DE;
  int c = 0;
  int of = 56;
  for (int i = 0; i < 8; i++) {
    if (c >= 8) {
      (store_double_word_data +i)->double_word[1] =
          (store_double_word_data +i)->double_word[1] | (temp_arr >> of);
      of = of - 8;
    }
    (store_double_word_data +i)->double_word[0] =
        ((store_double_word_data +i)->double_word[0] >> c) | temp_arr;
    (store_double_word_data +i)->double_word[0] =
        (store_double_word_data +i)->double_word[0] << c;

    c = c + 8;
  }

  int check = 1;

  for (int i = 0; i < 8; i++) {
    if ((store_double_word_data +i)->double_word[0] ^
        (store_double_word_expected_data +i)->double_word[0]) {
      printf("%s", "mismatch in store_double_word_data at index:");
      printf("%i", i);
      printf("%s\n", "0");
      check = 0;
    }
    if ((store_double_word_data +i)->double_word[1] ^
        (store_double_word_expected_data +i)->double_word[1]) {
      printf("%s", "mismatch in store_double_word_data at index:");
      printf("%i", i);
      printf("%s\n", "1");
      check = 0;
    }
  }
  return check;
}  // store_double_word_test

int main() {
  int sbt = store_byte_test();
  if (sbt) {
    printf("%s\n", "store_byte_test passed");
  } else {
    printf("%s\n", "store_byte_test failed");
  }

  int shwt = store_half_word_test();
  if (shwt) {
    printf("%s\n", "store_half_word_test passed");
  } else {
    printf("%s\n", "store_half_word_test failed");
  }

  int swt = store_word_test();
  if (swt) {
    printf("%s\n", "store_word_test passed");
  } else {
    printf("%s\n", "store_word_test failed");
  }

  int sdwt = store_double_word_test();
  if (sdwt) {
    printf("%s\n", "store_double_word_test passed");
  } else {
    printf("%s\n", "store_double_word_test failed");
  }

  return 0;
}  // main
