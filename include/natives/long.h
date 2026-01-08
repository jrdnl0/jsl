# ifndef __JSL_LONG_STATS_H__
# define __JSL_LONG_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_long_workspace_tag
{
    const long * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_long_workspace_t;

double jsl_long_stats_mean(const long vector[], size_t length, size_t step);
double jsl_long_stats_variance(const long vector[], size_t length, size_t step);
double jsl_long_stats_stddev(const long vector[], size_t length, size_t step);
double jsl_long_stats_tss(const long vector[], size_t length, size_t step);
double jsl_long_stats_absdev(const long vector[], size_t length, size_t step);
double jsl_long_stats_skew(const long vector[], size_t length, size_t step);
double jsl_long_stats_kurtosis(const long vector[], size_t length, size_t step);
double jsl_long_stats_lag1_auto(const long vector[], size_t length, size_t step);


double jsl_long_stats_variance_fixed(const long vector[], size_t length, size_t step, const double mu);
double jsl_long_stats_stddev_fixed(const long vector[], size_t length, size_t step, const double mu);
double jsl_long_stats_tss_fixed(const long vector[], size_t length, size_t step, const double mu);
double jsl_long_stats_absdev_fixed(const long vector[], size_t length, size_t step, const double mu);
double jsl_long_stats_skew_fixed(const long vector[], size_t length, size_t step, const double mu, const double std);
double jsl_long_stats_kurtosis_fixed(const long vector[], size_t length, size_t step, const double mu, const double std);
double jsl_long_stats_lag1_auto_fixed(const long vector[], size_t length, size_t step, const double mu);



# endif