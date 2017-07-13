Stewart, Matthew, matthew9@stanford.edu

Short Answer Questions:

1. The render method is defined as "const" which means that it cannot change any values definded outside the method. Therefore when it tries to change the value of m_random_delta, the compiler generates an error.

2. When random delta is called in the constructor, it is only called once at the generation of the cube and therefore the cubes breath smoothly. However when the call is made inside the update method, it means that the m_current_breath_amt is jumping between values giving it the juttery weird look. This happens because the m_random_delta can be any random value from 0 to 5 and is being updated every call to update. Therefore both m_pos.z and the scale matrix are both getting values that end up "jumping" because of the discontinuous natureof the values of m_current_breath_amt. This accounts for the buggy look of the cubes.

3. The line of code belongs in the constructor. If we place it in the update method, then we are unnecessarily recalculating the m_random_delta value for every call to update. This uses more computing power and is inefficient.

Understanding Shaders:

a. In line 14 the order of operations was flipped and model was multiplied by view instead of vice versa.

b. Here the light ambient strength was increased. On line 17, instead of setting it equal to .1 it was set to be some higher value (somewhere around .7).

c. Line 30, the power to which the max(dot(viewDir, reflectDir), 0.0) is being raised is increased significantly resulting in a much higher value of the float spec. In addition it appears that specular strength is multiplied by some constant to increase its value as well.

Open-ended portion:

<Please write instructions here for us to experience your unique creation!>

Extra Credit:

1. <YOUR ANSWER HERE>

2. <YOUR ANSWER HERE>

3. <YOUR ANSWER HERE>

