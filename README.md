# miniRT
MiniRT stands for "Mini Ray-Tracer", which is a program that creates an image by mathemnaticaly simulating rays of light going through every pixel.
This technic alows to render realistic looking pictures. This program can generate regular Phong model difusion, recursive reflection AND refraction,
calculating multi spot and colored lights, custom skydomes, regular and bump textures. All of this with objects like Sphere, Plane, Cylinder, Triangle and Hyperboloid
And here are some examples : 
# Examples
<img width="1094" alt="Screen Shot 2023-01-27 at 7 40 44 PM" src="https://user-images.githubusercontent.com/91738456/215499287-703d39b3-ed7d-44ad-9d82-fe07fe35c15d.png">
<img width="1368" alt="Screen Shot 2023-01-27 at 7 53 45 PM" src="https://user-images.githubusercontent.com/91738456/215499384-fbbe67d1-44aa-4771-9813-17775ef54292.png">
<img width="1868" alt="Screen Shot 2023-01-30 at 3 46 43 PM" src="https://user-images.githubusercontent.com/91738456/215509354-791183f7-5d80-49f1-b413-060de678849f.png">
<img width="1461" alt="Screen Shot 2023-01-27 at 7 39 54 PM" src="https://user-images.githubusercontent.com/91738456/215499430-ff132084-4c27-42f4-a814-4aa40884eafa.png">
<img width="1819" alt="Screen Shot 2023-01-22 at 10 27 21 PM" src="https://user-images.githubusercontent.com/91738456/215499473-0542c636-97ac-4177-b4a9-672ae5e13fd4.png">
<img width="1546" alt="Screen Shot 2023-01-22 at 7 58 26 PM" src="https://user-images.githubusercontent.com/91738456/215499503-6326ca27-aff9-4597-b77f-4468de9104b3.png">
<img width="1868" alt="Screen Shot 2023-01-30 at 3 46 43 PM" src="https://user-images.githubusercontent.com/91738456/215511904-3c86d95c-3914-45db-a3d1-7a65419aae45.png">

# Usage
Install by cloning the repo

```bash
git clone https://github.com/statvej/miniRT.git
```
Then compile by using make
And run the program with scene input as command line argument

```bash
./miniRT scenes/reflective_corner.rt
```

It's posible to create your own scenes or change pre-made ones.
Here are options for objets

| Abbriviation | Name | Properties |
| :------------ |:---------------:| :----- |
| c | camera | Center, direction, fov |
| A | ambient light |  intensity, collor |
| l | light  |  position, intensity color |
| sp | sphere |  position, diameter, color, material |
| pl | plane |  position, surface normal, color, material |
| cy | cylinder |  position, tube axis direction, diameter, length, color, material |
| tr | trinagle |  point1, point2, point3, color, material |
| hy | hyperboloid |  origin point, axis orientation, semi-major axis parameteres, radius, color, material |

Materials are stored as numbers, here are explanation of what those numbers mean:

| Number | Type |
|:------| :--------|
| 1 | Regular surface |
| 2 | Reflective surface |
| 3 | Refractive (only with spheres) |
| 4 | Earth texture no bump (only with spheres) |
| 5 | Mirror |
| 6 | Space texture (only with spheres) |
| 7 | Checkered surface |
| 8 | Sun texture (only with spheres) |
| 9 | Moon texture no bump (only with spheres) |
| 10 | Mars texture no bump (only with spheres) |
| 11 | Mercury texture no bump (only with spheres) |
| 12 | Venus texture no bump (only with spheres) |
| 13 | Jupiter texture no bump (only with spheres) |
| 14 | Earth texture WITH bumps (only with spheres) |
