
# ifndef __JSL_INT_STATS_H__
# define __JSL_INT_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_int_workspace_tag
{
    const int * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_int_workspace_t;


double jsl_int_stats_mean(const int vector[], size_t length, size_t step);
double jsl_int_stats_variance(const int vector[], size_t length, size_t step);
double jsl_int_stats_stddev(const int vector[], size_t length, size_t step);
double jsl_int_stats_tss(const int vector[], size_t length, size_t step);
double jsl_int_stats_absdev(const int vector[], size_t length, size_t step);
double jsl_int_stats_skew(const int vector[], size_t length, size_t step);
double jsl_int_stats_kurtosis(const int vector[], size_t length, size_t step);
double jsl_int_stats_lag1_auto(const int vector[], size_t length, size_t step);


double jsl_int_stats_variance_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_stddev_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_tss_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_absdev_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_skew_fixed(const int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_int_stats_kurtosis_fixed(const int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_int_stats_lag1_auto_fixed(const int vector[], size_t length, size_t step, const double mu);



# endif