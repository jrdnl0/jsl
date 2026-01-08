
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

jsl_int_workspace_t * jsl_int_stats_alloc_space(const int * vector, size_t length);
void jsl_int_stats_dealloc_space(jsl_int_workspace_t *);
void jsl_int_stats_calculate_workspace(jsl_int_workspace_t *);
const double jsl_int_workspace_return_mean(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_variance(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_stddev(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_tss(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_skew(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_kurtosis(const jsl_int_workspace_t *);
const double jsl_int_workspace_return_lag1_auto(const jsl_int_workspace_t *);

/**
 * @brief Returns the arithmetic mean of a set of integers.
 */
double jsl_int_stats_mean(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the variance of a set of integers.
 */
double jsl_int_stats_variance(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the standard deviation of a set of integers.
 */
double jsl_int_stats_stddev(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the total sum of squares of a set of integers.
 */
double jsl_int_stats_tss(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the absolute deviance of a set of integers.
 */
double jsl_int_stats_absdev(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the skewness of a set of integers.
 */
double jsl_int_stats_skew(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the kurtosis of a set of integers.
 */
double jsl_int_stats_kurtosis(const int vector[], size_t length, size_t step);

/**
 * @brief Returns the lag1 autocorrelation of a set of integers.
 */
double jsl_int_stats_lag1_auto(const int vector[], size_t length, size_t step);


double jsl_int_stats_variance_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_stddev_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_tss_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_absdev_fixed(const int vector[], size_t length, size_t step, const double mu);
double jsl_int_stats_skew_fixed(const int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_int_stats_kurtosis_fixed(const int vector[], size_t length, size_t step, const double mu, const double std);
double jsl_int_stats_lag1_auto_fixed(const int vector[], size_t length, size_t step, const double mu);



# endif