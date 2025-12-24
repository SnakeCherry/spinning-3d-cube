= What is a cube?

A cube is a square, which is then rotated then offset by a certain amount in all other directions to combine to make a cube

= What do we need?

Therefore this is then rotated by the rotation matrix

$vec(x, y, z) dot R_x (theta) dot R_y (theta) dot R_z (theta)$ is the equation required to describe how the cube rotates around all three axes.

This expands to:
$
  vec(x, y, z) dot mat(
    1, 0, 0;
    0, cos theta, - sin theta;
    0, sin theta, cos theta;
  )
  dot mat(
    cos theta, 0, sin theta;
    0, 1, 0;
    - sin theta, 0, cos theta;
  ) dot mat(
    cos theta, - sin theta, 0;
    sin theta, cos theta, 0; 0, 0, 1;
  )
$

= Converting to Quaternions

A quaternion is of the shape $(q_0, q_1, q_2, q_3)$
$
  "When given the rotation matrix, " R = mat(r_"1,1", r_"1,2", r_"1,3"; r_"2,1", r_"2,2", r_"2,3"; r_"3,1", r_"3,2", r_"3,3";) \ \
  "We can find the equivalent quaternions by this method:" \
$

== Step 1: Find the magnitude of each *quaternion* component.
$
  |q_0| = sqrt(frac(1+r_("1,1")+r_("2,2") + r_("3,3"), 4)) \
  |q_1| = sqrt(frac(1+r_("1,1")-r_("2,2") - r_("3,3"), 4)) \
  |q_2| = sqrt(frac(1-r_("1,1")+r_("2,2") - r_("3,3"), 4)) \
  |q_3| = sqrt(frac(1-r_("1,1")-r_("2,2") + r_("3,3"), 4)) \
$

== Step 2: Resolve the signs
=== To resolve the signs, find the largest out of $q_0, q_1, q_2, q_3$ and assume the sign is positive.
Then follow this table

#table(
  rows: 4,
  columns: 4,
  [$q_0$ is largest], [$q_1$ is largest], [$q_2$ is largest], [$q_3$ is largest],
  [$
    q_1 = frac(r_"3,2" - r_"2,3", 4 dot q_0)
  $],
  [$
    q_0 = frac(r_"3,2" - r_"2,3", 4 dot q_0)
  $],
  [$
    q_0 = frac(r_"1,3" - r_"3,1", 4 dot q_2)
  $],
  [$
    q_0 = frac(r_"2,1" - r_"1,2", 4 dot q_3)
  $],

  [],
)

=== Quaternion for $R_x$:
$
R_x (theta) =   mat(
    1, 0, 0;
    0, cos theta, - sin theta;
    0, sin theta, cos theta;
  )
$

Quaternion for $R_x (theta)$ = $(q_0, q_1, q_2, q_3)$
$
|q_0| = sqrt(frac(1 + 1 + cos theta + cos theta, 4))
$

$
|q_1| = sqrt(frac(1 + 1 - cos theta - cos theta, 4))
$

$
|q_2| = sqrt(frac(1 - 1 + cos theta - cos theta, 4))
$

$
|q_3| = sqrt(frac(1 - 1 - cos theta + cos theta, 4))
$

The maximum value is 1, and $|q_0|=|q_1|$



#pagebreak()
#bibliography("refs.bib", style: "institute-of-electrical-and-electronics-engineers")
