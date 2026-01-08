
# include "include/natives/int.h"
# include <malloc.h>
# include <math.h>

jsl_int_workspace_t * jsl_int_stats_alloc_space(const int * vector, size_t length)
{
    jsl_int_workspace_t * new_workspace = (jsl_int_workspace_t *)malloc(sizeof(jsl_int_workspace_t));
    new_workspace->vector = vector;
    new_workspace->length = length;
    jsl_int_stats_calculate_workspace(new_workspace);
    return new_workspace;
}

void jsl_int_stats_dealloc_space(jsl_int_workspace_t * wptr)
{
    free(wptr);
}

void jsl_int_stats_calculate_workspace(jsl_int_workspace_t * wptr)
{
    wptr->mean = jsl_int_stats_mean(wptr->vector, wptr->length, 1);
    wptr->variance = jsl_int_stats_variance_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean);
    wptr->stddev = jsl_int_stats_stddev_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean);
    wptr->tss = jsl_int_stats_tss_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean);
    wptr->absdev = jsl_int_stats_absdev_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean);
    wptr->skew = jsl_int_stats_skew_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean, (const double)wptr->stddev);
    wptr->kurtosis = jsl_int_stats_kurtosis_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean, (const double)wptr->stddev);
    wptr->lag1_auto = jsl_int_stats_lag1_auto_fixed(wptr->vector, wptr->length, 1, (const double)wptr->mean);
}

const double jsl_int_workspace_return_mean(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->mean;
}

const double jsl_int_worksapce_return_variance(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->variance;
}

const double jsl_int_workspace_return_stddev(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->stddev;
}

const double jsl_int_workspace_return_tss(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->tss;
}

const double jsl_int_workspace_return_skew(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->skew;
}

const double jsl_int_workspace_return_kurtosis(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->kurtosis;
}

const double jsl_int_workspace_return_lag1_auto(const jsl_int_workspace_t * wspace)
{
    return (const double) wspace->kurtosis;
}


double jsl_int_stats_mean(const int vector[], size_t length, size_t step)
{
    double mean = 0.0;
    for (size_t k = 0; k < length; k++)
        mean += (vector[k * step] - mean) / (k + 1);
    return mean;
}


double jsl_int_stats_variance(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    double var = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = vector[k * step] - mean;
        var += (term * term);
    }

    var /= (length - 1);
    return var;
}


double jsl_int_stats_stddev(const int vector[], size_t length, size_t step)
{
    return (double)sqrt(jsl_int_stats_variance(vector, length, step));
}


double jsl_int_stats_tss(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    double sigma = 0;


    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mean);
        sigma += (term * term);
    }

    return sigma;
}


double jsl_int_stats_absdev(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    double absdev = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = vector[k * step] - mean;
        if (term < 0)
            absdev += -1 * term;
        else
            absdev += term;
    }

    absdev /= length;
    return absdev;
}


double jsl_int_stats_skew(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    double stddev = jsl_int_stats_stddev(vector, length, step);

    double skew = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mean) / stddev;
        skew += (term * term * term);
    }
    skew /= length;
    return skew;
}

double jsl_int_stats_kurtosis(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    double stddev = jsl_int_stats_stddev(vector, length, step);

    double kurtosis = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mean) / stddev;
        kurtosis += (term * term * term * term);
    }

    kurtosis = (kurtosis / length) - 3;
    return kurtosis;
}


double jsl_int_stats_lag1_auto(const int vector[], size_t length, size_t step)
{
    double mean = jsl_int_stats_mean(vector, length, step);
    
    double numerator = 0;
    double denominator = 0;


    for (size_t k = 0; k < length; k++)
    {
        const double dterm = vector[k * step] - mean;
        denominator += dterm * dterm;
        if (k >= 1)
            numerator += (vector[k * step] - mean) * (vector[(k - 1) * step] - mean);
    }
    
    return numerator / denominator;
}


double jsl_int_stats_variance_fixed(const int vector[], size_t length, size_t step, const double mu)
{
    double var = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = vector[k * step] - mu;
        var += (term * term);
    }

    var /= (length - 1);
    return var;
}

double jsl_int_stats_stddev_fixed(const int vector[], size_t length, size_t step, const double mu)
{
    return (double)sqrt(jsl_int_stats_variance_fixed(vector, length, step, mu));
}


double jsl_int_stats_tss_fixed(const int vector[], size_t length, size_t step, const double mu)
{
    double sigma = 0;


    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mu);
        sigma += (term * term);
    }

    return sigma;
}

double jsl_int_stats_absdev_fixed(const int vector[], size_t length, size_t step, const double mu)
{
    double absdev = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = vector[k * step] - mu;
        if (term < 0)
            absdev += -1 * term;
        else
            absdev += term;
    }

    absdev /= length;
    return absdev;
}

double jsl_int_stats_skew_fixed(const int vector[], size_t length, size_t step, const double mu, const double std)
{
    double skew = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mu) / std;
        skew += (term * term * term);
    }
    skew /= length;
    return skew;
}


double jsl_int_stats_kurtosis_fixed(const int vector[], size_t length, size_t step, const double mu, const double std)
{
    double kurtosis = 0;

    for (size_t k = 0; k < length; k++)
    {
        const double term = (vector[k * step] - mu) / std;
        kurtosis += (term * term * term * term);
    }

    kurtosis = (kurtosis / length) - 3;
    return kurtosis;
}


double jsl_int_stats_lag1_auto_fixed(const int vector[], size_t length, size_t step, const double mu)
{
    double numerator = 0;
    double denominator = 0;


    for (size_t k = 0; k < length; k++)
    {
        const double dterm = vector[k * step] - mu;
        denominator += dterm * dterm;
        if (k >= 1)
            numerator += (vector[k * step] - mu) * (vector[(k - 1) * step] - mu);
    }
    
    return numerator / denominator;
}