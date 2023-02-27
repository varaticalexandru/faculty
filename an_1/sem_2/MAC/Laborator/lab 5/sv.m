function [vs_min, vs_max, nrc, nrcc] = sv(A)
    vs = svd(A);
    vs_min = min(vs);
    vs_max = max(vs);
    nrc = cond(A);
    nrcc = rcond(A);
end