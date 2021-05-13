# project_RTracing
study_project

This program uses school library mlx (libmlx.dylib), my library libft includes useful functions and some duplicate functions of C99 standard libraries.

This project is rendering computer generated images by Ray Tracing. \
The program takes as a first argument a scene description file *.rt with information about some scene. And optional second argument "--save" to save the rendered image in bmp format.
File *.rt can include the following elements: \
Resolution (R x y) \
Ambient lightning (A brigth r,g,b) \
Camera (c x,y,z normalized_orientation_vector FOV) \
Light (l  x,y,z brigth r,g,b) \
Sphere (sp x,y,z diameter r,g,b) \
Plane (pl x,y,z normalized_orientation_vector r,g,b) \
Square (sq x,y,z normalized_orientation_vector side_size r,g,b) \
Cylinder (cy x,y,z normalized_orientation_vector diameter height r,g,b) \
Triangle (tr x1,y1,z1 x2,y2,z2 x3,y3,z3 r,g,b)

For compile and run program \
make && ./miniRT scene/SCENE_NAME.rt (--save)
