
# include "include/natives/char.h"

# include <malloc.h>
# include <math.h>

jsl_char_workspace_t * jsl_construct_char_workspace(const char * vector, size_t length)
{
    jsl_char_workspace_t * new_space = (jsl_char_workspace_t *)malloc(sizeof(jsl_char_workspace_t));
    new_space->vector = vector;
    new_space->length = length;
    jsl_calculate_char_workspace_stats(new_space);
    return new_space;
}


void jsl_calculate_char_workspace_stats(jsl_char_workspace_t * W)
{
    W->mean = jsl_char_stats_mean(W->vector, W->length, 1);
    W->variance = jsl_char_stats_variance_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->stddev = jsl_char_stats_stddev_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->tss = jsl_char_stats_tss_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->absdev = jsl_char_stats_absdev_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->skew = jsl_char_stats_skew_fixed(W->vector, W->length, 1, (const double)W->mean, (const double)W->stddev);
    W->kurtosis = jsl_char_stats_kurtosis_fixed(W->vector, W->length, 1, (const double)W->mean, (const double)W->stddev);
    W->lag1_auto = jsl_char_stats_lag1_auto_fixed(W->vector, W->length, 1, (const double)W->mean);
}


void jsl_destruct_char_workspace(jsl_char_workspace_t * W) { free(W); }


double jsl_char_stats_mean(const char vector[], size_t length, size_t step)
{
    double mu = 0;
    for (size_t k = 0; k < length; k++)
        mu += vector[k * step];
    return (mu / length);
}




