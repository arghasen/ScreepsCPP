
#include "process.hpp"

namespace slowdeath {
namespace os {

Process::Process(PId pid, std::string name, ProcessData data, Process* parent)
:pid_(pid),
name_(name),
data_(std::move(data)),
parent_(parent)
{
}
} // namespace os
} // namespace slowdeath