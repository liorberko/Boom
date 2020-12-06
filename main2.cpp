// #include <iostream>
// #include "library.h"


// int main()
// {
//     void* DS = Init();
//     if (AddCourse(DS, 111, 3) == SUCCESS)
//     {
//         std::cout << "Add course num 111"<<std::endl;
//     }
//     if (AddCourse(DS, 222, 3) == SUCCESS)
//     {
//         std::cout << "Add course num 222"<<std::endl;
//     }
//     if (AddCourse(DS, 333, 3) == SUCCESS)
//     {
//         std::cout << "Add course num 333"<<std::endl;
//     }
//     if (AddCourse(DS, 444, 3) == SUCCESS)
//     {
//         std::cout << "Add course num 444"<<std::endl;
//     }
//     if (AddCourse(DS, -123, 3) == INVALID_INPUT)
//     {
//         std::cout << "Succesfully didn't add cours -123"<<std::endl;
//     }
//     if (RemoveCourse(DS,444) == SUCCESS)
//     {
//         std::cout << "Remove course num 444"<<std::endl;
//     }
//     if (WatchClass(DS, 111, 0, 3) == SUCCESS )
//     {
//         int temp11 = 0;
//         int* temp1 = &temp11;
//         TimeViewed(DS,111, 0 ,temp1);
//         std::cout<< "WatchClass SUCCES, add "<< *temp1 << " minutes"<<std::endl;
//     }
//     if (WatchClass(DS, 111, 2, 3) == SUCCESS )
//     {
//         int temp22 = 0;
//         int* temp2 = &temp22;
//         TimeViewed(DS,111, 2 ,temp2);
//         std::cout<< "WatchClass SUCCES, add "<< *temp2 << " minutes"<<std::endl;
//     }
//     if (WatchClass(DS, 222, 2, 2) == SUCCESS )
//     {
//         int temp33 = 0;
//         int* temp3 = &temp33;
//         TimeViewed(DS,222, 2 ,temp3);
//         std::cout<< "WatchClass SUCCES, add "<< *temp3 << " minutes"<<std::endl;
//     }
//     int courses[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
//     int classes[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
//     if (GetMostViewedClasses(DS,8,courses,classes) == SUCCESS)
//     {
//         for (int i = 0; i<8 ; i++)
//         {
//             std::cout << "cours: " << courses[i] << " class: " << classes[i] << std::endl; 
//         }
//     }
//     Quit(&DS);
//     return 0;
// }