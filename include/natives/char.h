# ifndef __JSL_CHAR_STATS_H__
# define __JSL_CHAR_STATS_H__

# ifndef size_t
# include <stddef.h>
# endif


typedef struct jsl_char_workspace_tag
{
    const char * vector;
    size_t length;

    double mean;
    double variance;
    double stddev;
    double tss;
    double absdev;
    double skew;
    double kurtosis;
    double lag1_auto;

} jsl_char_workspace_t;

jsl_char_workspace_t * jsl_construct_char_workspace(const char * vector, size_t length);
void jsl_calculate_char_workspace_stats(jsl_char_workspace_t * W);
void jsl_destruct_char_workspace(jsl_char_workspace_t * W);



double jsl_char_stats_mean(const char vector[], size_t length, size_t step);
double jsl_char_stats_variance(const char vector[], size_t length, size_t step);
double jsl_char_stats_stddev(const char vector[], size_t length, size_t step);
double jsl_char_stats_tss(const char vector[], size_t length, size_t step);
double jsl_char_stats_absdev(const char vector[], size_t length, size_t step);
double jsl_char_stats_skew(const char vector[], size_t length, size_t step);
double jsl_char_stats_kurtosis(const char vector[], size_t length, size_t step);
double jsl_char_stats_lag1_auto(const char vector[], size_t length, size_t step);


double jsl_char_stats_variance_fixed(const char vector[], size_t length, size_t step, const double mu);
double jsl_char_stats_stddev_fixed(const char vector[], size_t length, size_t step, const double mu);
double jsl_char_stats_tss_fixed(const char vector[], size_t length, size_t step, const double mu);
double jsl_char_stats_absdev_fixed(const char vector[], size_t length, size_t step, const double mu);
double jsl_char_stats_skew_fixed(const char vector[], size_t length, size_t step, const double mu, const double std);
double jsl_char_stats_kurtosis_fixed(const char vector[], size_t length, size_t step, const double mu, const double std);
double jsl_char_stats_lag1_auto_fixed(const char vector[], size_t length, size_t step, const double mu);



# endif