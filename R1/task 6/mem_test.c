#include <stdio.h>
#include <stdint.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3
#define ARR_SIZE 8

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };


int compare_arr_t_arrays(const arr_t a[], const arr_t b[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < NO_WORDS; j++) {
            if (a[i].double_word[j] != b[i].double_word[j])
                return 0;  // not equal
        }
    }
    return 1;  // all equal
}


int store_byte_test () {
    uint16_t values[8] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE };

    for (size_t i = 0; i < 8; i++) {
        store_byte_data[i].double_word[0] |=  (uint64_t)(values[i]) << (8 * i); // set byte i
    }

    int equal = compare_arr_t_arrays(store_byte_data, store_byte_expected_data, 8);
   return equal;
    
}


int store_half_word_test() {
    uint16_t values[8] = { 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE };

    for (size_t i = 0; i < 8; i++) {
        if (i < 7) {
            store_half_word_data[i].double_word[0] |= (uint64_t)(values[i]) << (8 * i);
        } else {
            store_half_word_data[i].double_word[0] |= ((uint64_t)(values[i] & 0x00FF)) << 56;

            store_half_word_data[i].double_word[1] |= ((uint64_t)(values[i] >> 8));
        }
    }

    return compare_arr_t_arrays(store_half_word_data, store_half_word_expected_data, 8);
}


int store_word_test() {
    uint32_t values[8] = { 
        0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 
        0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE 
    };

    for (size_t i = 0; i < 8; i++) {
        if (i <= 8) {
            store_word_data[i].double_word[0] |= ((uint64_t)(values[i]) << (8 * i));
        }
        if (i >= 5){
            store_word_data[i].double_word[1] |= ((uint64_t)(values[i] >> 8 * (4-i)));
        }
    }

    return compare_arr_t_arrays(store_word_data, store_word_expected_data, 8);
}



int store_double_word_test() {

    uint64_t value = 0xDEADBEEFF00DC0DE;


   for (size_t i = 0; i < 8; i++) {
        if (i <= 8) {
            store_double_word_data[i].double_word[0] |= ((uint64_t)(value) << (8 * i));
        }
        if (i >= 1){
            store_double_word_data[i].double_word[1] |= ((uint64_t)(value >> 8 * (8-i)));
        }
    }

    return compare_arr_t_arrays(store_double_word_data, store_double_word_expected_data, 8);
}


int print_mem(arr_t* arr){
   printf("\n");
   
   for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 2; j++) {
            printf("%016llx ", arr[i].double_word[j]);  // hex format, padded
        }
        printf("\n");
    }
   printf("\n");
   
   return 0;
}

int main() {
    int store_byte_test_result = store_byte_test();
    printf("Store byte test %s\n", store_byte_test_result ? "PASS" : "FAIL");

    int store_half_word_test_result = store_half_word_test();
    printf("Store half word test %s\n", store_half_word_test_result ? "PASS" : "FAIL");

    int store_word_test_result = store_word_test();
    printf("Store word test %s\n", store_word_test_result ? "PASS" : "FAIL");

    int store_double_word_test_result = store_double_word_test();
    printf("Store double word test %s\n", store_double_word_test_result ? "PASS" : "FAIL");

    return 0;
}


