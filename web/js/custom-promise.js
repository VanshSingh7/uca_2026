function NewPromise(executorFunction) {
    this.state = "pending";
    this.result = undefined;

    let successCallbacks = [];
    let errorCallbacks = [];

    const resolve = (value) => {
        if (this.state !== "pending") return;

        this.state = "fulfilled";
        this.result = value;

        successCallbacks.forEach(callback => {
            callback(value);
        });
    };

    const reject = (error) => {
        if (this.state !== "pending") return;

        this.state = "rejected";
        this.result = error;

        errorCallbacks.forEach(callback => {
            callback(error);
        });
    };

    this.then = function (successCallback) {
        return new NewPromise((resolveNext, rejectNext) => {

            const callback = (value) => {
                try {
                    const result = successCallback(value);
                    resolveNext(result);
                } catch (error) {
                    rejectNext(error);
                }
            };

            if (this.state === "pending") {
                successCallbacks.push(callback);
            } else if (this.state === "fulfilled") {
                callback(this.result);
            }
        });
    };

    this.catch = function (errorCallback) {
        return new NewPromise((resolveNext, rejectNext) => {

            const callback = (error) => {
                try {
                    const result = errorCallback(error);
                    resolveNext(result);
                } catch (error) {
                    rejectNext(error);
                }
            };

            if (this.state === "pending") {
                errorCallbacks.push(callback);
            } else if (this.state === "rejected") {
                callback(this.result);
            }
        });
    };

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}


const promise = new NewPromise((resolve, reject) => {
    resolve(5);
});

promise
    .then(value => {
        return value * 2;
    })
    .then(value => {
        return value * 5;
    })
    .then(value => {
        console.log(value);
    });