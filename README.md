random-number-ecdf
==================
- [Generate random numbers from empirical cumulative distribution function in MATLAB - Stack Overflow](https://stackoverflow.com/questions/49178265/generate-random-numbers-from-empirical-cumulative-distribution-function-in-matla)


### Prebuilts
- [dirkarnez/armadillo-prebuilt](https://github.com/dirkarnez/armadillo-prebuilt)


### Octave example (working + proved correct on [Online Graph Maker · Plotly Chart Studio](https://chart-studio.plotly.com/create/#/))
The two coin ecdf (0 head inclusive to 1 head exclusive = 0.25, 1 head inclusive to 2 heads exclusive= 0.75, 2 heads inclusive = 1)
```octave
y = rand(10, 1)
x = interp1(empirical_cdf([0, 1, 2], [0, 1, 1, 2] /**/), [0, 1, 2], y, 'linear');
####                         ^1          ^2                  ^3
```
- ^1 is the x-axis of ecdf
- ^2 is the ecdf samples collected
- ^3 is the x-axis for random numbers, should be the same as ^1
