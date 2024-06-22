
#ifndef Q_MEM_OBJ_DEF_H
#define Q_MEM_OBJ_DEF_H

#include "q_mem_obj.h"
#include "q_mem_map.h"

Queue qa_p1 = {
    .mem_base_in = FIFO_QA_P1_IN_BASE,
    .mem_base_out = FIFO_QA_P1_OUT_BASE,
    .ctrl_base = FIFO_QA_P1_IN_CSR_BASE
};

Queue qa_p2 = {
    .mem_base_in = FIFO_QA_P2_IN_BASE,
    .mem_base_out = FIFO_QA_P2_OUT_BASE,
    .ctrl_base = FIFO_QA_P2_IN_CSR_BASE
};

Queue qa_p3 = {
    .mem_base_in = FIFO_QA_P3_IN_BASE,
    .mem_base_out = FIFO_QA_P3_OUT_BASE,
    .ctrl_base = FIFO_QA_P3_IN_CSR_BASE
};

Queue qb_p1 = {
    .mem_base_in = FIFO_QB_P1_IN_BASE,
    .mem_base_out = FIFO_QB_P1_OUT_BASE,
    .ctrl_base = FIFO_QB_P1_IN_CSR_BASE
};

Queue qb_p2 = {
    .mem_base_in = FIFO_QB_P2_IN_BASE,
    .mem_base_out = FIFO_QB_P2_OUT_BASE,
    .ctrl_base = FIFO_QB_P2_IN_CSR_BASE
};

Queue qb_p3 = {
    .mem_base_in = FIFO_QB_P3_IN_BASE,
    .mem_base_out = FIFO_QB_P3_OUT_BASE,
    .ctrl_base = FIFO_QB_P3_IN_CSR_BASE
};

Queue qc_p1 = {
    .mem_base_in = FIFO_QC_P1_IN_BASE,
    .mem_base_out = FIFO_QC_P1_OUT_BASE,
    .ctrl_base = FIFO_QC_P1_IN_CSR_BASE
};

Queue qc_p2 = {
    .mem_base_in = FIFO_QC_P2_IN_BASE,
    .mem_base_out = FIFO_QC_P2_OUT_BASE,
    .ctrl_base = FIFO_QC_P2_IN_CSR_BASE
};

Queue qc_p3 = {
    .mem_base_in = FIFO_QC_P3_IN_BASE,
    .mem_base_out = FIFO_QC_P3_OUT_BASE,
    .ctrl_base = FIFO_QC_P3_IN_CSR_BASE
};

Queue qd_p1 = {
    .mem_base_in = FIFO_QD_P1_IN_BASE,
    .mem_base_out = FIFO_QD_P1_OUT_BASE,
    .ctrl_base = FIFO_QD_P1_IN_CSR_BASE
};

Queue qd_p2 = {
    .mem_base_in = FIFO_QD_P2_IN_BASE,
    .mem_base_out = FIFO_QD_P2_OUT_BASE,
    .ctrl_base = FIFO_QD_P2_IN_CSR_BASE
};

Queue qd_p3 = {
    .mem_base_in = FIFO_QD_P3_IN_BASE,
    .mem_base_out = FIFO_QD_P3_OUT_BASE,
    .ctrl_base = FIFO_QD_P3_IN_CSR_BASE
};

Queue qe = {
    .mem_base_in = FIFO_QE_IN_BASE,
    .mem_base_out = FIFO_QE_OUT_BASE,
    .ctrl_base = FIFO_QE_IN_CSR_BASE
};

#endif // Q_MEM_OBJ_DEF_H
