
# ifndef __JSL_DOUBLE_STATS_H__
# define __JSL_DOUBLE_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_double_workspace_tag
{
    const double * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_double_workspace_t;



double jsl_double_stats_mean(const double vector[], size_t length, size_t step);
double jsl_double_stats_variance(const double vector[], size_t length, size_t step);
double jsl_double_stats_stddev(const double vector[], size_t length, size_t step);
double jsl_double_stats_tss(const double vector[], size_t length, size_t step);
double jsl_double_stats_absdev(const double vector[], size_t length, size_t step);
double jsl_double_stats_skew(const double vector[], size_t length, size_t step);
double jsl_double_stats_kurtosis(const double vector[], size_t length, size_t step);
double jsl_double_stats_lag1_auto(const double vector[], size_t length, size_t step);


double jsl_double_stats_variance_fixed(const double vector[], size_t length, size_t step, const double mu);
double jsl_double_stats_stddev_fixed(const double vector[], size_t length, size_t step, const double mu);
double jsl_double_stats_tss_fixed(const double vector[], size_t length, size_t step, const double mu);
double jsl_double_stats_absdev_fixed(const double vector[], size_t length, size_t step, const double mu);
double jsl_double_stats_skew_fixed(const double vector[], size_t length, size_t step, const double mu, const double std);
double jsl_double_stats_kurtosis_fixed(const double vector[], size_t length, size_t step, const double mu, const double std);
double jsl_double_stats_lag1_auto_fixed(const double vector[], size_t length, size_t step, const double mu);



# endif