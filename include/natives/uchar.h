
# ifndef __JSL_UCHAR_STATS_H__
# define __JSL_UCHAR_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif

typedef struct jsl_uchar_workspace_tag
{
    const unsigned char * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_uchar_workspace_t;

double jsl_uchar_stats_mean(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_variance(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_stddev(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_tss(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_absdev(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_skew(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_kurtosis(const unsigned char vector[], size_t length, size_t step);
double jsl_uchar_stats_lag1_auto(const unsigned char vector[], size_t length, size_t step);


double jsl_uchar_stats_variance_fixed(const unsigned char vector[], size_t length, size_t step, const double mu);
double jsl_uchar_stats_stddev_fixed(const unsigned char vector[], size_t length, size_t step, const double mu);
double jsl_uchar_stats_tss_fixed(const unsigned char vector[], size_t length, size_t step, const double mu);
double jsl_uchar_stats_absdev_fixed(const unsigned char vector[], size_t length, size_t step, const double mu);
double jsl_uchar_stats_skew_fixed(const unsigned char vector[], size_t length, size_t step, const double mu, const double std);
double jsl_uchar_stats_kurtosis_fixed(const unsigned char vector[], size_t length, size_t step, const double mu, const double std);
double jsl_uchar_stats_lag1_auto_fixed(const unsigned char vector[], size_t length, size_t step, const double mu);



# endif