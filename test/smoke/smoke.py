import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

def configure_and_build():
    build = ROOT / "build"
    build.mkdir(exist_ok=True)
    subprocess.run(["cmake", "-S", str(ROOT), "-B", str(build)], check=True)
    subprocess.run(["cmake", "--build", str(build)], check=True)
    return build

def logger(build):
    exe = build / "logger_smoke"
    with tempfile.TemporaryDirectory() as run_dir:
        subprocess.run([str(exe)], cwd=run_dir, check=True)
        csv = Path(run_dir) / "detections.csv"
        assert csv.exists()
        assert csv.read_text().splitlines()[0] == "timestamp,path"

def image_saver(build):
    exe = build / "image_saver_smoke"
    with tempfile.TemporaryDirectory() as run_dir:
        subprocess.run([str(exe)], cwd=run_dir, check=True)
        raw = Path(run_dir) / "smoke_test.nv12"
        assert raw.exists()
        assert raw.stat().st_size > 0


def main():
    build = configure_and_build()
    logger(build)
    image_saver(build)
    

if __name__ == "__main__":
    main()
