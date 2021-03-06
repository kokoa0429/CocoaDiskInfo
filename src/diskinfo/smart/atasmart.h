#ifndef COCOA_DISK_INFO_SMART_ATASMART_H_
#define COCOA_DISK_INFO_SMART_ATASMART_H_

#include <stdlib.h>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>

#include "const.h"
#include "attribute.h"
#include "health.h"

extern "C" {
#include <atasmart.h>
}

namespace DiskInfo {
namespace SMART {
class ATASMART {
public:
  ATASMART() = default;
  ATASMART(const std::string _device);
  ATASMART(const ATASMART&) = default;
  uint64_t temperature() const;
  uint64_t powerOnTime() const;
  uint64_t powerOnCount() const;
  uint64_t capacity() const;
  std::string model() const;
  std::string serial() const;
  std::string firmware() const;
  const std::vector<Attribute> attr() const;
  std::string device() const;

private:
  std::pair<bool, uint64_t> temperature_;
  std::pair<bool, uint64_t> powerOnTime_;
  std::pair<bool, uint64_t> powerOnCount_;
  std::pair<bool, uint64_t> capacity_;
  std::vector<Attribute> attr_;
  std::string model_;
  std::string serial_;
  std::string firmware_;
  std::string device_;
  Health tempeHealth_;
};
} // namespace SMART
} // namespace DiskInfo

#endif
