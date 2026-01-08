
# ifndef __JSL_FLOAT_STATS_H__
# define __JSL_FLOAT_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_float_workspace_tag
{
    const float * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_float_workspace_t;


double jsl_float_stats_mean(const float vector[], size_t length, size_t step);
double jsl_float_stats_variance(const float vector[], size_t length, size_t step);
double jsl_float_stats_stddev(const float vector[], size_t length, size_t step);
double jsl_float_stats_tss(const float vector[], size_t length, size_t step);
double jsl_float_stats_absdev(const float vector[], size_t length, size_t step);
double jsl_float_stats_skew(const float vector[], size_t length, size_t step);
double jsl_float_stats_kurtosis(const float vector[], size_t length, size_t step);
double jsl_float_stats_lag1_auto(const float vector[], size_t length, size_t step);

double jsl_float_stats_variance_fixed(const float vector[], size_t size, size_t step, const double mu);
double jsl_float_stats_stddev_fixed(const float vector[], size_t size, size_t step, const double mu);
double jsl_float_stats_tss_fixed(const float vector[], size_t size, size_t step, const double mu);
double jsl_float_stats_absdev_fixed(const float vector[], size_t size, size_t step, const double mu);
double jsl_float_stats_skew_fixed(const float vector[], size_t size, size_t step, const double mu, const double std);
double jsl_float_stats_kurtosis_fixed(const float vector[], size_t size, size_t step, const double mu, const double std);
double jsl_float_stats_lag1_auto_fixed(const float vector[], size_t size, size_t step, const double mu);



# endif