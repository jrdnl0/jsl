
# ifndef __JSL_SHORT_STATS_H__
# define __JSL_SHORT_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif


typedef struct jsl_short_workspace_tag
{
    const short * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_short_workspace_t;

double jsl_short_stats_mean(const short vector[], size_t length, size_t step);
double jsl_short_stats_variance(const short vector[], size_t length, size_t step);
double jsl_short_stats_stddev(const short vector[], size_t length, size_t step);
double jsl_short_stats_tss(const short vector[], size_t length, size_t step);
double jsl_short_stats_absdev(const short vector[], size_t length, size_t step);
double jsl_short_stats_skew(const short vector[], size_t length, size_t step);
double jsl_short_stats_kurtosis(const short vector[], size_t length, size_t step);
double jsl_short_stats_lag1_auto(const short vector[], size_t length, size_t step);


double jsl_short_stats_variance_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_short_stats_stddev_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_short_stats_tss_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_short_stats_absdev_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_short_stats_skew_fixed(const short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_short_stats_kurtosis_fixed(const short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_short_stats_lag1_auto_fixed(const short vector[], size_t length, size_t step, const double mu);



# endif