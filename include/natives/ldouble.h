# ifndef __JSL_LDOUBLE_STATS_H__
# define __JSL_LDOUBLE_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_ldouble_workspace_tag
{
    const long double * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_ldouble_workspace_t;

double jsl_ldouble_stats_mean(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_variance(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_stddev(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_tss(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_absdev(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_skew(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_kurtosis(const short vector[], size_t length, size_t step);
double jsl_ldouble_stats_lag1_auto(const short vector[], size_t length, size_t step);


double jsl_ldouble_stats_variance_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_ldouble_stats_stddev_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_ldouble_stats_tss_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_ldouble_stats_absdev_fixed(const short vector[], size_t length, size_t step, const double mu);
double jsl_ldouble_stats_skew_fixed(const short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_ldouble_stats_kurtosis_fixed(const short vector[], size_t length, size_t step, const double mu, const double std);
double jsl_ldouble_stats_lag1_auto_fixed(const short vector[], size_t length, size_t step, const double mu);



# endif