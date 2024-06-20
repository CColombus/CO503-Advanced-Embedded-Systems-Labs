// #include "q_mem_obj.h"

#include <stdio.h>


void pr(int n);

int main() {
    // print hex with 8 0 padding
    // printf("Q1\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q1.mem_base_in,q1.mem_base_out,q1.ctrl_base);
    // printf("Q2\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q2.mem_base_in,q2.mem_base_out,q2.ctrl_base);
    // printf("Q3\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q3.mem_base_in,q3.mem_base_out,q3.ctrl_base);
    // printf("Q4\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q4.mem_base_in,q4.mem_base_out,q4.ctrl_base);
    // printf("Q5\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q5.mem_base_in,q5.mem_base_out,q5.ctrl_base);
    // printf("Q6\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q6.mem_base_in,q6.mem_base_out,q6.ctrl_base);
    // printf("Q1B\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q1b.mem_base_in,q1b.mem_base_out,q1b.ctrl_base);
    // printf("Q1C\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q1c.mem_base_in,q1c.mem_base_out,q1c.ctrl_base);
    // printf("Q1D\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q1d.mem_base_in,q1d.mem_base_out,q1d.ctrl_base);
    // printf("Q1E\n\tin: 0x%08X\n\tout: 0x%08X\n\tctrl: 0x%08X\n",q1e.mem_base_in,q1e.mem_base_out,q1e.ctrl_base);
    // return 0;
    int n = -987;
    pr(n);
    return 0;
}

void pr(int n){
        char buffer[20];
    int i = 0, sign;

    if ((sign = n) < 0)  // Record sign
        n = -n;          // Make n positive

    do {  // Generate digits in reverse order
        buffer[i++] = n % 10 + '0';  // Get next digit
    } while ((n /= 10) > 0);         // Delete it

    if (sign < 0)
        buffer[i++] = '-';

    buffer[i] = '\0';

    // Reverse the string
    int start = 0, end = i - 1;
    char temp;
    while (start < end) {
        temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    puts(buffer);  // Print string to stdout followed by a newline
}