#ifndef TEST_WINDEBUG_OUTPUT_H
#define TEST_WINDEBUG_OUTPUT_H

#include "test_output.h"

#include <sstream>
#include <memory>

namespace test
{

class windebug_output : public test_output
{
public:
    explicit windebug_output(bool striplf, bool use_tiny_mode);

	void start() override;
	void start_class(const std::string &class_name) override;
	void start_function(const std::string &class_name, const std::string &function_name) override;
	void end_function(const std::string &class_name, const std::string &function_name) override;
	void end_class(const std::string &class_name, const test_class_statistics &stats) override;
	void end(int class_count, const test_class_statistics &stats) override;

	void output_success(const std::string &message, int line, const char *file) override;
	void output_failure(const std::string &message, int line, const char *file) override;
	void output_exception(const std::string &message, const std::string &exceptiontext, int line, const char *file) override;
	void output_message(const std::string &message, int line, const char *file) override;
    void output_expected_fail(const std::string &expected, const std::string &message, int line = 0, const char *file = nullptr);

private:
	std::stringstream buffer;
	std::unique_ptr<test_output> generator;
	bool strip_lf;

	void dump_buffer();
    void dump_string(const std::string &message) const;
};

}

#endif
