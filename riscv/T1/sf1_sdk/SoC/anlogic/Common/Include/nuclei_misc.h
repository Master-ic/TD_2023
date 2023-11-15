#ifndef _NUCLEI_MISC_H
#define _NUCLEI_MISC_H

#ifdef __cplusplus
 extern "C" {
#endif

#define MISC_ENABLE_CORE   BIT(0)



#define MISC_POR_CAUSE         BIT(16)
#define MISC_NSYS_RST_CAUSE    BIT(17)
#define MISC_CORE_CAUSE        BIT(18)

#define MISC_ILM_ERROR_CAUSE  BIT(20)
#define MISC_DLM_ERROR_CAUSE   BIT(21)


#define MISC_NMI_ILM           BIT(0)
#define MISC_NMI_DLM           BIT(1)


#define MISC_NMI_EXT_PENDING   BIT(16)




/* CLOCK SELCEL */

#define MISC_CLOCK_SEL     BIT(0)
#define MISC_CLOCK_DIV     BITS(1,5)

/* Cache System Control*/
#define DCACHE_FLUSH_INVALIDATE       BITS(0ï¼?1)
#define DCACHE_FLUASH_INVPENDINH   BIT(2)
#define ICACHE_INVALIDATE  BIT(3)
#define ICACHE_INVPENDINH  BIT(4)


#define CLOCK_SEL_OCS   BIT(0)
#define CLOCK_SEL_DIVIDE   BITS(1,5)
#define CLOCK_SEL_DIVIDE_OFS 1

#define CLOCK_PPI_DIVIDE   BITS(6,9)
#define CLOCK_PPI_DIVIDE_OFS 6





typedef enum misc_dcache_flush_inv {
    MISC_DCACHE_FLUSH = 1,
    MISC_DCACHE_INVALIDATE = 3,
} MISC_DCACHE;



int32_t misc_reset_enable_core();

int32_t misc_reset_get_por_cause();

int32_t misc_reset_get_nsys_rst_cause();

int32_t misc_reset_get_core_cause();


int32_t misc_nmi_get_ext_pending();



int32_t misc_clock_sel_ocs();

int32_t misc_clock_sel_divide();

int32_t misc_set_clock_divide(int32_t clock_divide);

int32_t misc_get_clock_divide();


#ifdef __cplusplus
}
#endif
#endif /* _HBIRD_MISC_H */
