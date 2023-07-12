chrono::steady_clock::time_point begin = chrono::steady_clock::now();
chrono::steady_clock::time_point end = chrono::steady_clock::now();
chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

auto start_time = chrono::high_resolution_clock::now();
auto end_time = chrono::high_resolution_clock::now();
auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
std::cout << "Elapsed time: " << elapsed_time.count() << " ms\n";