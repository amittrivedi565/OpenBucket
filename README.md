# OpenBucket

----
OpenBucket is object storage service stores, not file system.

### Key characteristics

---
- Stores objects (binary blobs + metadata)
- Objects live inside buckets
- Accessed via HTTP APIs

```bucket_logic
bucket-name / object-key → data + metadata
```

### Core Features

---

1. Bucket Management
- Create Bucket
- Delete Bucket
- List Buckets
