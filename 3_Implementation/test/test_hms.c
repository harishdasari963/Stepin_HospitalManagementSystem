
#include "unity.h"
#include <functions.h>

#define PROJECT_NAME "hospital"

//list of function prototype



/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_exitt(void){
  TEST_ASSERT_EQUAL_STRING("EXITING THE PROGRAM",exitt());
    
}
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_exitt);
  return UNITY_END();
}
