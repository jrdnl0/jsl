
# ifndef __JSL_UINT_STATS_H__
# define __JSL_UINT_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_uint_workspace_tag
{
    const unsigned int * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_uint_workspace_t;


double jsl_uint_stats_mean(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_variance(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_stddev(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_tss(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_absdev(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_skew(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_kurtosis(const unsigned int vector[], size_t length, size_t step);
double jsl_uint_stats_lag1_auto(const unsigned int vector[], size_t length, size_t step);


double jsl_uint_stats_variance_fixed(const unsigned int vector[], size_t length, size_t step, const double mu);
double jsl_uint_stats_stddev_fixed(const unsigned int vector[], size_t length, size_t step, const double mu);
double jsl_uint_stats_tss_fixed(const unsigned int vector[], size_t length, size_t step, const double mu);
double jsl_uint_stats_absdev_fixed(const unsigned int vector[], size_t length, size_t step, const double mu);
double jsl_uint_stats_skew_fixed(const unsigned int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_uint_stats_kurtosis_fixed(const unsigned int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_uint_stats_lag1_auto_fixed(const unsigned int vector[], size_t length, size_t step, const double mu);



# endif