#include "BenchmarkGroups.h"
#include "../simulation/data_structures/CappedArray.h"
#include "../simulation/data_structures/ExpansibleArray.h"
#include "../util/macros.h"

struct big_object {
    big_object(){};
    int32_t fill[256];
};

CappedArray<int, 50> global_1;
ExpansibleArray<int, 10> global_2;
CappedArray<big_object, 50> global_3;
ExpansibleArray<big_object, 10> global_4;

BenchmarkGroups::BenchmarkGroups() {
    loop(i, 10) {
        global_1.push(42);
    }
    loop(i, 10) {
        global_2.push(42);
    }
}


template<int s, int l>
void push_max_size_int() {
    CappedArray<int, s> g;
    loop(i, l) {
        g.push(42);
    }
}

template<int s, int l>
void push_expansible_int() {
    ExpansibleArray<int, s> g;
    loop(i, l) {
        g.push(42);
    }
}

template<int s, int l>
void push_max_size_obj() {
    CappedArray<big_object, s> g;
    loop(i, l) {
        g.push(big_object());
    }
}

template<int s, int l>
void push_expansible_obj() {
    ExpansibleArray<big_object, s> g;
    loop(i, l) {
        g.push(big_object());
    }
}


void case7() {
    auto glou(global_1);
}
void case8() {
    auto glou(global_2);
}
void case9() {
    auto glou(global_3);
}
void case10() {
    auto glou(global_4);
}



void BenchmarkGroups::run(double allowed_time) {
    ASSERT(allowed_time > 0);

    cerr << "Running benckmark Groups :" << endl;
    this->m_time_control.set_checkpoint();

    this->register_case(
        new BenchmarkCase(
            "Push 30 int with max size 50",
            push_max_size_int<50,30>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Push 30 int with extended 40",
            push_expansible_int<40,30>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Push 30 int with extended 30",
            push_expansible_int<30,30>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Push 50 int with max size 50",
            push_max_size_int<50,50>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Push 50 int with extended 40",
            push_expansible_int<40,50>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Push 50 int with extended 30",
            push_expansible_int<30,50>
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Copy max size 50 with 10 elements (without copy overload)",
            &case7
        )
    );
    this->register_case(
        new BenchmarkCase(
            "Copy extended 10 with 10 elements",
            &case8
        )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 30 big_object with max size 50",
                    push_max_size_obj<50,30>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 30 big_object with extended 40",
                    push_expansible_obj<40,30>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 30 big_object with extended 30",
                    push_expansible_obj<30,30>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 50 big_object with max size 50",
                    push_max_size_obj<50,50>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 50 big_object with extended 40",
                    push_expansible_obj<40,50>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Push 50 big_object with extended 30",
                    push_expansible_obj<30,50>
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Copy max size 50 with 10 big elements (without copy overload)",
                    &case9
            )
    );
    this->register_case(
            new BenchmarkCase(
                    "Copy extended 10 with 10 big elements",
                    &case10
            )
    );


    for (auto benchmark_case : this->m_benchmark_cases) {
        benchmark_case->perform_case(
            allowed_time / this->m_benchmark_cases.size()
        );
    }
}