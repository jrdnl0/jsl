# ifndef __JSL_USHORT_STATS_H__
# define __JSL_USHORT_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_ushort_workspace_tag
{
    const unsigned short * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_ushort_workspace_t;


double jsl_ushort_stats_mean(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_variance(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_stddev(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_tss(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_absdev(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_skew(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_kurtosis(const unsigned short vector[], size_t length, size_t step);
double jsl_ushort_stats_lag1_auto(const unsigned short vector[], size_t length, size_t step);


double jsl_ushort_stats_variance_fixed(const unsigned short vector[], size_t length, size_t step, const double mu);
double jsl_ushort_stats_stddev_fixed(const unsigned short vector[], size_t length, size_t step, const double mu);
double jsl_ushort_stats_tss_fixed(const unsigned short vector[], size_t length, size_t step, const double mu);
double jsl_ushort_stats_absdev_fixed(const unsigned short vector[], size_t length, size_t step, const double mu);
double jsl_ushort_stats_skew_fixed(const unsigned short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_ushort_stats_kurtosis_fixed(const unsigned short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_ushort_stats_lag1_auto_fixed(const unsigned short vector[], size_t length, size_t step, const double mu);



# endif