/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2014 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_
#define XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_

#include "xenia/kernel/objects/xfile.h"

namespace xe {
namespace vfs {

class STFSContainerEntry;

class STFSContainerFile : public XFile {
 public:
  STFSContainerFile(KernelState* kernel_state, Mode mode,
                    STFSContainerEntry* entry);
  ~STFSContainerFile() override;

 protected:
  X_STATUS ReadSync(void* buffer, size_t buffer_length, size_t byte_offset,
                    size_t* out_bytes_read) override;

 private:
  STFSContainerEntry* entry_;
};

}  // namespace vfs
}  // namespace xe

#endif  // XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_
