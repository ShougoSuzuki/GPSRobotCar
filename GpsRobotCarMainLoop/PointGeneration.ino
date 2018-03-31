void PointGeneration(float xa, float ya, float xb, float yb, float theta){
  float r = 0.00005;
  float rad45 = 45.0 * PI / 180.0;
  float rad135 = 135.0 * PI / 180.0;
  float rad225 = 225.0 * PI / 180.0;
  float rad315 = 315.0 * PI / 180.0;
  float radTheta = theta * PI / 180.0;

  Tnorth_pointArray[0] = (xa+xb)/2.0;
  Teast_pointArray[0] = (ya+yb)/2.0;

  Tnorth_pointArray[1] = (xa + r * cos(rad135 + radTheta));
  Teast_pointArray[1] = (ya + r * sin(rad135 + radTheta));

  Tnorth_pointArray[2] = (xa + r * cos(rad225 + radTheta));
  Teast_pointArray[2] = (ya + r * sin(rad225 + radTheta));

  Tnorth_pointArray[3] = Tnorth_pointArray[0];
  Teast_pointArray[3] = Teast_pointArray[0];

  Tnorth_pointArray[4] = (xb + r * cos(rad45 + radTheta));
  Teast_pointArray[4] = (yb + r * sin(rad45 + radTheta));

  Tnorth_pointArray[5] = (xb + r * cos(rad315 + radTheta));
  Teast_pointArray[5] = (yb + r * sin(rad315 + radTheta));
}

