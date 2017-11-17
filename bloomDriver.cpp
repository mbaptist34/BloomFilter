#include <assert.h>
#include "Bloom.h"
#include <iostream>

int main() {
    
    Bloom *bloom = new Bloom(100, .01);

    std::string Matt = "Matt";
    std::string Rene = "Rene";
    std::string Hello = "Hello";

    assert(bloom->contains(&Matt, sizeof("Matt")) == false);
    assert(bloom->contains(&Hello, sizeof("Hello")) == false);
    assert(bloom->contains(&Rene, sizeof("Rene")) == false);

    std::cout<<"Empty contains tests passed."<<std::endl;

    bloom->add(&Matt, sizeof("Matt"));
    bloom->add(&Hello, sizeof("Hello"));
    bloom->add(&Rene, sizeof("Rene"));

    assert(bloom->contains(&Matt, sizeof("Matt")) == true);
    assert(bloom->contains(&Hello, sizeof("Hello")) == true);
    assert(bloom->contains(&Rene, sizeof("Rene")) == true);

    assert(bloom->contains(&Matt, sizeof("Matt")) != false);
    assert(bloom->contains(&Hello, sizeof("Hello")) != false);
    assert(bloom->contains(&Rene, sizeof("Rene")) != false);



    std::cout<<"Add tests passed."<<std::endl;

    std::cout<<"All tests passed."<<std::endl;

    delete bloom;
}



